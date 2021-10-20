const resirock = document.getElementById("resirock");
const resirockgasa = document.getElementById("resirock-gasa");
const resisteal = document.getElementById("resisteal");
const resistealgasa = document.getElementById("resisteal-gasa");
const resiice = document.getElementById("resiice");
const resiicegasa = document.getElementById("resiice-gasa");
const boo = document.getElementById("boo");
const boogasa = document.getElementById("boo-gasa");
const gung = document.getElementById("gung");
const gunggasa = document.getElementById("gung-gasa");
let sho
showgasa = 0;
if (resirock!=null){
    resirock.onclick = function(){
        if(showgasa){
            console.log("1");
            resirockgasa.style.display = "none";
            showgasa = 0;
        }
        else{
            console.log("0");
            resirockgasa.style.display = "block";
            showgasa = 1;
        }
    }
    resisteal.onclick = function(){
        if(showgasa){
            console.log("1");
            resistealgasa.style.display = "none";
            showgasa = 0;
        }
        else{
            console.log("0");
            resistealgasa.style.display = "block";
            showgasa = 1;
        }
    }
    resiice.onclick = function(){
        if(showgasa){
            console.log("1");
            resiicegasa.style.display = "none";
            showgasa = 0;
        }
        else{
            console.log("0");
            resiicegasa.style.display = "block";
            showgasa = 1;
        }
    }
    boo.onclick = function(){
        if(showgasa){
            console.log("1");
            boogasa.style.display = "none";
            showgasa = 0;
        }
        else{
            console.log("0");
            boogasa.style.display = "block";
            showgasa = 1;
        }
    }
    gung.onclick = function(){
        if(showgasa){
            console.log("1");
            gunggasa.style.display = "none";
            showgasa = 0;
        }
        else{
            console.log("0");
            gunggasa.style.display = "block";
            showgasa = 1;
        }
    }
    resirock.onclick = function(){
        if(showgasa){
            console.log("1");
            resirockgasa.style.display = "none";
            showgasa = 0;
        }
        else{
            console.log("0");
            resirockgasa.style.display = "block";
            showgasa = 1;
        }
    }
}
img = document.getElementById("logo");

img.onmouseover=function(){
    img.src = "./pic/bbuzizic.png";
    img.style.width = "200px"
}
img.onmouseout=function(){
    img.src = "./pic/electric.png";
    img.style.width = "100px";

}

// function test() {
//     console.log('test');
// }
// function doBlink() { 

// const blink = document.body.getElementsByClassName("hong")
// var i=0
// while(1){
//     if(i%2==0){
//         blink.
//     }
// } 
// function startBlink() { 
// if (blink) 
// setInterval("doBlink()",350) 
// } 
// window.onload = startBlink; 

