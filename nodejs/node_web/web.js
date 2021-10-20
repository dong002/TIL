// "use strict"
const axios = require("axios");
const link = 'http://localhost:3000/signup';
function check(){
    const id = document.getElementsByName("make_id");
    const pw = document.getElementsByName("make_pw");
    // ax({
    //     method:"POST",
    //     url:link,
    //     data:{
    //         "id": id.value,
    //         "pw": pw.value
    //     }
    // }).then
    axios.post(link, {
        "id": id.value,
        "pw": pw.value
      })
      .then(function (response) {
        console.log(response);
      })
      .catch(function (error) {
        console.log(error);
      });
}

