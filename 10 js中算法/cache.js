// 浏览器会将文件缓存到Cache目录，第二次请求时浏览器会先检查Cache目录下是否含有该文件，如果有，并且还没到Expires设置的时间，即文件还没有过期，那么此时浏览器将直接从Cache目录中读取文件，而不再发送请求
// Expires是服务器响应消息头字段，在响应http请求时告诉浏览器在过期时间前浏览器可以直接从浏览器缓存取数据，而无需再次请求,这是HTTP1.0的内容，现在浏览器均默认使用HTTP1.1,所以基本可以忽略
// Cache-Control与Expires的作用一致，都是指明当前资源的有效期，控制浏览器是否直接从浏览器缓存取数据还是重新发请求到服务器取数据,如果同时设置的话，其优先级高于Expires
// 7.1 Cache-Control
// private 客户端可以缓存
// public 客户端和代理服务器都可以缓存
// max-age=60 缓存内容将在60秒后失效
// no-cache 需要使用对比缓存验证数据,强制向源服务器再次验证
// no-store 所有内容都不会缓存，强制缓存和对比缓存都不会触发
// Cache-Control:private, max-age=60, no-cache


    let http = require('http');
    let fs = require('fs');
    let path = require('path');
    let mime = require('mime');
    let crypto = require('crypto');
    http.createServer(function (req, res) {
        let file = path.join(__dirname, req.url);
        console.log(file);

        fs.stat(file, (err, stat) => {
            if (err) {
                sendError(err, req, res, file, stat);
            } else {
                send(req, res, file);
            }
        });
    }).listen(8080);
    function send(req, res, file) {
        let expires = new Date(Date.now() + 60 * 1000);
        res.setHeader('Expires', expires.toUTCString());
        res.setHeader('Cache-Control', 'max-age=60');
        res.writeHead(200, { 'Content-Type': mime.lookup(file) });
        fs.createReadStream(file).pipe(res);
    }
    function sendError(err, req, res, file, etag) {
        res.writeHead(400, { "Content-Type": 'text/html' });
        res.end(err ? err.toString() : "Not Found");
    }