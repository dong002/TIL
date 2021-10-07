const http = require('http');
const fs = require('fs');
const url = require('url');

var app = http.createServer((req,res) => { // '/' 
    console.log(req.url);  
    var _url = req.url;
    var Query_data = url.parse(_url, true).query;//?
    console.log(url.parse(_url, true));
    console.log(Query_data.id);
    if (_url == "/"){
        //var data = fs.readFileSync("./node_web/index.html",{encoding:"utf-8", flag:"r"});//?
        // res.end(data); 
        _url = "/node_web/index.html";
    }
    if (_url == "/dong"){
        res.write("dongdong");
        res.end();
    }
    if (_url == "/favicon.ico"){
        return res.writeHead(404);
    }
    res.writeHead(200);//?
    res.end(fs.readFileSync(__dirname+_url));
})
app.listen(3000,() => {//?
    console.log("server is working");
});