// 引入依赖
const EventEmitter = require("events");
const fs = require("fs");

class ReadableStream extends EventEmitter {
    constructor(path, options = {}) {
        super();
        this.path = path; // 读取文件的路径
        this.flags = options.flags || "r"; // 文件标识位
        this.encoding = options.encoding || null; // 字符编码
        this.fd = options.fd || null; // 文件描述符
        this.mode = options.mode || 0o666; // 权限位
        this.autoClose = options.autoClose || true; // 是否自动关闭
        this.start = options.start || 0; // 读取文件的起始位置
        this.highWaterMark = options.highWaterMark || 64 * 1024; // 每次读取文件的字节数

        this.reading = false; // 如果正在读取，则不再读取
        this.emitReadable = false; // 当缓存区的长度等于 0 的时候， 触发 readable
        this.arr = []; // 缓存区
        this.len = 0; // 缓存区的长度
        this.pos = this.start; // 下次读取文件的位置（变化的）

        // 创建可读流要打开文件
        this.open();

        this.on("newListener", type => {
            if (type === "readable") {
                this.read(); // 监听readable就开始读取
            }
        });
    }
}

ReadableStream.prototype.open = function() {
    fs.open(this.path, this.flags, this.mode, (err, fd) => {
        if (err) {
            this.emit("error", err);
            if (this.autoClose) {
                this.destroy();
                return;
            }
        }
        this.fd = fd;
        this.emit("open");
    });
};
ReadableStream.prototype.detroy = function() {
    if (typeof this.fd === "number") {
        fs.close(fd, () => {
            this.emit("close");
        });
        return;
    }
    this.emit("close");
};
ReadableStream.prototype.read = function(n) {
    // 如果读取大于了 highWaterMark，重新计算 highWaterMark，并重新读取
    if (n > this.len) {
        // 计算新的 highWaterMark，方法摘自 NodeJS 源码
        this.highWaterMark = computeNewHighWaterMark(n);
        this.reading = true;
        this._read();
    }

    // 将要返回的数据
    let buffer;

    // 如果读取的字节数大于 0 小于等于当前缓存 Buffer 的总长度
    if (n > 0 && n <= this.len) {
        // 则从缓存中取出
        buffer = Buffer.alloc(n);

        let current; // 存储每次从缓存区读出的第一个 Buffer
        let index = 0; // 每次读取缓存 Buffer 的索引
        let flag = true; // 是否结束整个 while 循环的标识

        // 开始读取
        while ((current = this.arr.shift()) && flag) {
            for (let i = 0; i < current.length; i++) {
                // 将缓存中取到的 Buffer 的内容读到自己定义的 Buffer 中
                buffer[index++] = current[i];

                // 如果当前索引值已经等于了读取个数，结束 for 循环
                if (index === n) {
                    flag = false;

                    // 取出当前 Buffer 没有消耗的
                    let residue = current.slice(i + 1);

                    // 在读取后维护缓存的长度
                    this.len -= n;

                    // 如果 BUffer 真的有剩下的就给塞回到缓存中
                    if (residue.length) {
                        this.arr.unshift(residue);
                    }

                    break;
                }
            }
        }
    }

    // 如果当前 读取的 Buffer 为 0，将触发 readable 事件
    if (this.len === 0) {
        this.emitReadable = true;
    }

    // 如果当前的缓存区大小小于 highWaterMark，就要读取
    if (this.len < this.highWaterMark) {
        // 如果不是正在读取才开始读取
        if (!this.read) {
            this.reading = true;
            this._read(); // 正真读取的方法
        }
    }

    // 将 buffer 转回创建可读流设置成的编码格式
    if (buffer) {
        buffer = this.encoding ? buffer.toString(this.encoding) : buffer;
    }

    return buffer;
};
ReadableStream.prototype._read = function() {
    if (typeof this.fd !== "number") {
        return this.once("open", () => _read());
    }
    // 创建本次读取的 Buffer
    let buffer = Buffer.alloc(this.highWaterMark);

    // 读取文件
    fs.read(
        this.fd,
        buffer,
        0,
        this.highWaterMark,
        this.pos,
        (err, bytesRead) => {
            if (bytesRead > 0) {
                this.arr.push(buffer); // 缓存
                this.len += bytesRead; // 维护缓存区长度
                this.pos += bytesRead; // 维护下一次读取位置
                this.reading = false; // 读取完毕

                // 触发 readable 事件
                if (this.emitReadable) {
                    // 触发后更改触发状态为 false
                    this.emitReadable = false;
                    this.emit("readable");
                }
            } else {
                // 如果读完触发结束事件
                this.emit("end");
            }
        }
    );
};

// 导出模块
module.exports = ReadableStream;