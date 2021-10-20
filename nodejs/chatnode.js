const app=require("express");
const http=require("http").createServer(http);
const io = require('socket.io')(http);
const port = 3000;
http.listen(port,()=>{
    console.log("ㄹㅇㅋㅋ")
});


io.on('connection', (socket)=>{
    console.log(socket.id,"connected");

    socket.emit('msg',`${socket.id}연결 되었농`);

    socket.on('msg',(data)=>{
        console.log(socket.id, data);

        socket.emit('msg',`Server : "${data}"받았습니당`)
    })
})