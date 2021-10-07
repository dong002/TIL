const { ApplicationCommandPermissionsManager } = require("discord.js");
const express=require("express");
const fs=require("fs");
const app=express();
const port=3000
const mysql     = require('mysql');
const connection = mysql.createConnection({
  host     : 'localhost',
  port     : '3306',
  user     : 'root',
  password : 'youtube',
  database : 'student'
});
const insert = "INSERT INTO prectice (id,password) VALUES (?,?)";
const select = "SELECT id FROM prectice WHERE id=?";
connection.connect((err)=>{
    if (err){
      console.log(err);
    }  else {
      console.info("연결됬다 멍");
    }
  
});
function push(id,pwd) {
    let param=[id,pwd]
    connection.query(insert,param,(err,rows,fields)=>{
        if(err){
          console.log(err);
        }
    })
} 
function sec(id){
    let param=id
    connection.query(select,param,(err,rows,fields)=>{
        if(err){
            console.error(err);
        }
        else{
            
        }
    })
}

// const lgbt=document.querySelector("button")


app.use(express.json())
app.use(express.urlencoded({ extended: true }));
function login(){
    const user={
        id: id.value,
        paword: ps.value,
    };
    console.log(user)
}

app.get('/',(req,res)=>{
    fs.readFile("./node_web/index.html","utf-8",(err,data)=>{
        if(err){
            console.error(err)
        }
        else{
            res.writeHead(200,{'Content-Type':'text/html'})
            res.end(data)
        }
    })
})
app.get('/login',(req,res)=>{
    fs.readFile("./node_web/checkbox.html","utf-8",(err,data)=>{
        const user = req.body
        if(err){
            console.error(err)
        }
        else{
            res.writeHead(200,{'Content-Type':'text/html'})
            res.end(data)
        }
    })
})
app.post('/login',(req,res)=>{
    const user = req.body;
})
app.post('/signup', (req, res) => {
    const user = req.body
    push(user.make_id,user.make_pw)

    res.send('시발');
})

app.get('/HTML',(req,res)=>{
    fs.readFile("./node_web/1.html","utf-8",(err,data)=>{
        if(err){
            console.error(err)
        }
        else{
            res.writeHead(200,{'Content-Type':'text/html'})
            res.end(data)
        }
    })
})
app.get('/CSS',(req,res)=>{
    fs.readFile("./node_web/2.html","utf-8",(err,data)=>{
        if(err){
            console.error(err)
        }
        else{
            res.writeHead(200,{'Content-Type':'text/html'})
            res.end(data)
        }
    })
})
app.get('/JavaScript',(req,res)=>{
    fs.readFile("./node_web/3.html","utf-8",(err,data)=>{
        if(err){
            console.error(err)
        }
        else{
            res.writeHead(200,{'Content-Type':'text/html'})
            res.end(data)
        }
    })
})
app.get('/signup',(req,res)=>{
    fs.readFile("./node_web/sign.html","utf-8",(err,data)=>{
        if(err){
            console.error(err)
        }
        else{

            res.writeHead(200,{'Content-Type':'text/html'})
            res.end(data)
        }
    })
})
app.listen(port,()=>{
    console.log("서버 작동");
})