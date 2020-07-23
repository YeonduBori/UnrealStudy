# UnrealStudy
Unreal engine 4 &amp; C++ Study

### 20-05-30
개인적으로 C++에서 신기했던 것

1. C#만 주구장창 하던 입장에선
클래스 배열선언과 동시에 초기화 되는 것은 신기했다.
2. 메모리 누수
```
char n = 'a';
char *p = new char[1024];
p = &n;
```
결론적으로 가비지 메모리 생성방식과 같다. 하지만 C++에선 가비지 컬렉터가 없기 때문에 더 주의해서 짜야할것
3. 힙이 꽉 차면 Null 반환
4. inline함수
짤막하게 호출되는 함수에 대해 오히려 한 줄 실행보다 함수를 불러오고 다시 해당 명령어 실행된 줄로 돌아가는 과정이 더 걸리는 오버헤드가 발생
그래서 그런 부분에 대해 함수호출 대신에 정말 함수 내부에 있는 코드를 삽입, 다만 getter/setter 같이 자주 호출되는 경우는 전반적인
코드 크기를 증가시키는 단점이 있다.

### 20-07-23
https://www.udemy.com/course/unrealblueprint/
https://www.udemy.com/course/unrealcourse/
아래 두 강좌를 들으면서 그대로 따라가볼 생각
