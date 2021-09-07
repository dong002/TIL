const express = require('express');
const http = require('http');
const fs = require('fs');
const app = express();
const port = 3000;
const port1 = 8080;

//app.use(extends : false)

const server = http.createServer((req, res) => {
    console.log(req.method);
    var url = req.url;
    if (req.url == '/dongdong') {
        res.write('dongdong fuck them');
        res.end();
    }
    if (req.url == '/web') {
        const data = fs.readFileSync('./node_web/index.html',
              {encoding:'utf8', flag:'r'});//flag 권한지정
        res.end(data);
    }
    res.write('FUck');
    res.end();
}).listen(port1, () => {
    console.log('http 서버 입니다.')
})


app.get('/', (req, res) => {
    console.log(req);
    res.sendFile(__dirname + '/node_web/index.html');
})

app.listen(port, () => {
    console.log('서버 온');
})