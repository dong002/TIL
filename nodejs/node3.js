const http = require("http");
const fs = require("fs");
const url = require("url");
const port1 = 3000;
const app = http.createServer((req,res) => {
    var _url = req.url;
    var querydata = url.parse(_url,true).query;
    var title = querydata.id;
    if(_url == "/") {
        title = "Welcome!"; 
    }
    if (_url == "/favicon.ico"){
        return res.writeHead(404);
    }
    
    res.writeHead(200);
    fs.readFile(`data/${querydata.id}`, 'utf8',(err,description) => {
        var template = `
        <!doctype html>
        <html>
        <head>
        <title>WEB1 - ${title}</title>
        <meta charset="utf-8">
        </head>
        <body>
        <h1><a href="/">WEB</a></h1>
        <ul>
        <li><a href="/?id=HTML">HTML</a></li>
        <li><a href="/?id=CSS">CSS</a></li>
        <li><a href="/?id=JavaScript">JavaScript</a></li>
        </ul>
        <h2>${title}</h2>
        <p>${description}</p>
        <p style="margin-top:45px;">HTML elements are the building blocks of HTML pages. With HTML constructs, images and other objects, such as interactive forms, may be embedded into the rendered page. It provides a means to create structured documents by denoting structural semantics for text such as headings, paragraphs, lists, links, quotes and other items. HTML elements are delineated by tags, written using angle brackets.
        </p>
        </body>
        </html>
        `
        ;
        res.end(template);
    });

}).listen(port1,() => {
    console.log("멍멍");
});