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
