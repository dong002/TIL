var i = prompt("단을입력하세요");
        var j;
        
        document.write(`<div>`);
        for (j = 1; j < 10; j++){
            document.write(` ${i} *  ${j} = ${i * j}<br>`);
        }
        document.write(`</div>`);
var v = prompt("시작단");
        var k = prompt("끝단");
        var i;
        for (; v <= k; v++){
            document.write(`<div>`);
            for(i=1;i<10;i++)
            document.write(` ${v} *  ${i} = ${i * v}<br>`);
            document.write(`</div>`);
        }