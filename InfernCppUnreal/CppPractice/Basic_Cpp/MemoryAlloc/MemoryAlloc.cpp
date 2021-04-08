#include <iostream>
using namespace std;

// 실행할 코드가 저장될 영역 -> 코드 영역
// 전역/정적 변수 -> 데이터 영역
// 지역 변수/매개 변수 -> 스택 영역
// 동적 할당 -> 힙 영역
// 동적할당과 연관된 함수/ 연산자 : malloc, free, new, delete, new[], delete[]

class Monster
{
public:
    int _hp;
    int _x;
    int _y;
};

int main()
{
    // 유저 영역 [메모장]
    return 0;
}

