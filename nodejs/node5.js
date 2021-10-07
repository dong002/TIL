const fs = require("fs");
const url = require("url");
const http = require("http");
const port = 3000;
const app = http.createServer((req,res) => {
    var _url = req.url;
    var queryData = url.parse(_url,true).query;
    var title = queryData.id;
    function templateHTML(title,list,description){
    return`<!doctype html>
    <html>
    <head>
    <title>WEB1 - ${title}</title>
    <meta charset="utf-8">
    </head>
    <body>
    <h1><a href="/">WEB</a></h1>
    ${list}
    <h2>${title}</h2>
    <p>${description}</p>
    <p style="margin-top:45px;">HTML elements are the building blocks of HTML pages. With HTML constructs, images and other objects, such as interactive forms, may be embedded into the rendered page. It provides a means to create structured documents by denoting structural semantics for text such as headings, paragraphs, lists, links, quotes and other items. HTML elements are delineated by tags, written using angle brackets.
    </p>
    </body>
    </html>`;
    }
        
    fs.readdir('./data',((err,filelist) => {
        console.log(filelist);
        fs.readFile(`./data/${title}`,((err,description)=>{

            if (title === undefined){
                title = "welcome";
                description = "hello js";
            }
            var list = '<ul>';
            var i = 0;
            while(i < filelist.length){
                list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li></ul>`;
                i++;
            }
            var template = templateHTML(title,list,description);
            res.writeHead(200, {"Content-Type":"text/html"});
            res.end(template);
        }))
    }));

    if (_url == "favicon.ico"){
        return res.writeHead(404);
    }
}).listen(port,'10.120.74.57',() =>{
    console.log("sever is running");
})