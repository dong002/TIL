const http = require("http");
const express = require("express");
const fs = require("fs");
const url = require("url");
const path = require('path');
const port = 3000;
const app = express();
app.use(express.json());
app.use(express.static("../submit"))

app.use(express.urlencoded({ extended: true }));
app.set('views', __dirname + '/submit');
app.set('view engine', 'html');
console.log(__dirname)

    app.get('/login9812.html',(req,res)=>{
        // fs.readFile('../login9812.html', (err, data) => {
        //     if(err) {
        //         console.log(err)
        //         console.log(__dirname);
        //         res.status(500).send('시발');
        //     }
        //     else {
        //         res.writeHead(200, {'Content-Type':'text/html'})
        //         res.end(data);
        //     }
            res.sendFile("C:\\Users\\user\\Desktop\\my-prectice\\login9812.html")
            res.end();
        //     console.log(res);
        //})
    //     var _url = req.url;
    // var dh = fs.readFile("../submit/index.html",(err,des)=>{
    //        console.log(des)
    //        console.log(err);
    //        const buffer = Buffer.from(des, "utf-8")
    //     //res.writeHead(200,{"Content-type":"text/html"});
    //     res.write(buffer);
    //     res. end(dh);`
    //console.log(__dirname);
     //   res.sendFile('C:\\Users\\user\\Desktop\\my-prectice\\submit\\index.html');
    });
    //     //console.log(req.body);
    // })
// const bodyparser = require("body-paser");
// const app = http.createServer((req,res) =>{
//     var _url = req.url;
//     var dh = fs.readFile("../submit/index.html",(err,des)=>{
//            console.log(err);
//            const buffer = Buffer.from(des, "utf-8")
//         //res.writeHead(200,{"Content-type":"text/html"});
//         res.write(buffer);
//         res.end(dh);
//     });

//}).listen(port,'10.120.74.57',()=>{
  //  console.log("server is running");
//})

app.listen(3000, () => {
    console.log('시발');
})