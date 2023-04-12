const express = require("express");
const app = express();
const port = 3000;
const fs = require("fs");
app.use(express.json());
// app.use(express.static("./node_web"))
// app.use(express.urlencoded({extended: true}))
console.log(__dirname);
app.get('/',(req,res)=>{
    fs.readFile('./node_web/checkbox.html','utf8', (err,data) =>{
        if(err){
            console.log(err);
        }
        else{
            res.writeHead(200, {'Content-Type':'text/html'})
            res.end(data);
        }
    })
    // res.sendFile("C:\\Users\\user\\Desktop\\github\\my-prectice\\nodejs\\node_web\\checkbox.html")
    // res.end()
});
app.listen(port, () =>{
    console.log('서버 게시다 이말아니겠노');
})