![아아아](https://kr.object.ncloudstorage.com/dreamhack-content/page/d93ebd8d44183538e008843f2b814271ccc49795238660d115d82b335312954d.jpg)
# 개요
XSS 공격이 보편화 됨에 따라 자연스럽게 XSS를 필터링하는 방식도 늘어나고 있다

**하지만** 잘못된 방식으로 필터링된 XSS필터링은 오히려  공격자로 하여금 공격의 기회를 제공해준다.

누군가가 말했듯 보안은 허술한것보다 보안의 허점을 남기고 안심하는게 위험하다

<br>

 # 불충분한 XSS 필터링
 특정 문자열을 필터링할때, 상황에 따라 우회 할 수 있는 방법이 있는데 먼저
 ## 1. Unicode escape sequence를 통한 우회
Unicode escape sequence란 아스키코드처럼 유니코드를 코드포인트와 매핑한 표 비스무리한것인데, 이를 이용해 우회할 수 있다
``` JS
var foo = "\u0063ookie";  // 결과: cookie
var bar = "cooki\x65";  // 결과: cookie
\u0061lert(document.cookie);  // 결과: alert(document.cookie)
```
위와 같이 해당하는 문자를 그와 대응하는 코드포인트로 작성하면 된다.
## 2. Computed member access를 통한 우회
Computed member access는 아래와 같이 객체의 특정속성에 접근할때 속성이름을 동적으로 계산하는 기능이다
``` JS
document["coo"+"kie"] == document["cookie"] == document.cookie
```
이제 1번 방법과 2번 방법을 이용하면?
``` JS
alert(document["\u0063ook" + "ie"]);  // alert(document.cookie)
window['al\x65rt'](document["\u0063ook" + "ie"]);  // alert(document.cookie)
```
처럼 사용할 수 있다.

**하지만** 아예 " ' 와 같은 문자열을 사용할 수 없는 경우가 있을 수 있다.
## 3. 템플릿 리터럴
템플릿 리터럴은 백틱 (`)을 이용한 표현식을 허용하는 문자열 리터럴로 백틱안에 ${}형태로 표현식을 사용할 수 있다
``` JS
var foo = "Hello";
var bar = "World";
var baz = `${foo},
${bar} ${1+1}.`; // "Hello,\nWorld 2."
```
그런데 백틱조차 막힌다면?
## 4. RegExp 객체
/Hello World/ 와 같이 정규표현식을 이용하여 우회할 수도 있다
``` JS
var foo = /Hello World!/.source;  // "Hello World!"
var bar = /test !/ + [];  // "/test !/"
```
아니면 아예 전부다 숫자로 치환할 수도 있다
## 5. String.fromCharCode 함수
``` JS
var foo = String.fromCharCode(72, 101, 108, 108, 111);  // "Hello"
```
또 하나의 방법으로 아예 내장함수나 문자열에서 한글자씩 가져오는 방법도 취할 수 있다.
``` JS
var baz = history.toString()[8] + // "H"
(history+[])[9] + // "i"
(URL+0)[12] + // "("
(URL+0)[13]; // ")" ==> "Hi()
```
