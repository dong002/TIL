const mysql      = require('mysql');
const connection = mysql.createConnection({
  host     : 'localhost',
  port     : '3306',
  user     : 'root',
  password : 'youtube',
  database : 'student'
});
const insert = "INSERT INTO student_table (id,name,grade,major,phone) VALUES (?,?,?,?,?)";
const param = ['ㄹㅇㅋㅋㅋㅋㅋ','김동현','1','보안','010-4280-3948']; 
const erase = "DELETE FROM student_table WHERE name='김동현'";
connection.connect((err)=>{
  if (err){
    console.log(err);
  }  else {
    console.info("연결됬다 멍");
  }

});
connection.query(insert,param,(err,rows,fields)=>{
  if(err){
    console.log(err);
  }
});
const see = connection.query('SELECT * from student_table', function (error, results, fields) {
  if (error) {
      console.log(error);
  }
  console.log(results);
});
connection.query(erase,(err,rows,fields)=>{
  if(err){
    console.log(err);
  }
  else{
    console.log("pop");
  }
})



connection.end();