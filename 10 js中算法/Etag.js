// ETag是实体标签的缩写，根据实体内容生成的一段hash字符串,可以标识资源的状态。当资源发生改变时，ETag也随之发生变化。 ETag是Web服务端产生的，然后发给浏览器客户端。

// 客户端想判断缓存是否可用可以先获取缓存中文档的ETag，然后通过If-None-Match发送请求给Web服务器询问此缓存是否可用。
// 服务器收到请求，将服务器的中此文件的ETag,跟请求头中的If-None-Match相比较,如果值是一样的,说明缓存还是最新的,Web服务器将发送304 Not Modified响应码给客户端表示缓存未修改过，可以使用。
// 如果不一样则Web服务器将发送该文档的最新版本给浏览器客户端


    let http = require('http');
    let fs = require('fs');
    let path = require('path');
    let mime = require('mime');
    let crypto = require('crypto');
    http.createServer(function (req, res) {
        let file = path.join(__dirname, req.url);
        fs.stat(file, (err, stat) => {
            if (err) {
                sendError(err, req, res, file, stat);
            } else {
                let ifNoneMatch = req.headers['if-none-match'];
                let etag = crypto.createHash('sha1').update(stat.ctime.toGMTString() + stat.size).digest('hex');
                if (ifNoneMatch) {
                    if (ifNoneMatch == etag) {
                        res.writeHead(304);
                        res.end();
                    } else {
                        send(req, res, file, etag);
                    }
                } else {
                    send(req, res, file, etag);
                }
            }
        });
    }).listen(8080);
    function send(req, res, file, etag) {
        res.setHeader('ETag', etag);
        res.writeHead(200, { 'Content-Type': mime.lookup(file) });
        fs.createReadStream(file).pipe(res);
    }
    function sendError(err, req, res, file, etag) {
        res.writeHead(400, { "Content-Type": 'text/html' });
        res.end(err ? err.toString() : "Not Found");
    }
