#include <iostream>
using namespace std;

#pragma region 동적할당
//// 실행할 코드가 저장될 영역 -> 코드 영역
//// 전역/정적 변수 -> 데이터 영역
//// 지역 변수/매개 변수 -> 스택 영역
//// 동적 할당 -> 힙 영역
//// 동적할당과 연관된 함수/ 연산자 : malloc, free, new, delete, new[], delete[]
//
//// new[] / delete[]
//// new가 malloc에 비해 좋긴 한데 배열과 같이 N개 데이터를 같이 할당하려면?
//
//// new/delete vs malloc/free
//// - 사용 편의성 -> new/delete 승!
//// 타입에 상관 없이 특정한 크기의 메모리 영역을 할당받으려면? -> malloc/free 승!
//
//// 그런데 둘의 가장 근본적인 중요한 차이는?
//// malloc/free는 함수 new/delete는 연산자(operator)
//// new/delete는 생성타입이 클래스일 경우 생성자/ 소멸자를 호출해준다!
//class Monster
//{
//public:
//    Monster()
//    {
//        cout << "Monster 생성자 호출!" << endl;
//    }
//    ~Monster()
//    {
//        cout << "Monster 소멸자 호출!" << endl;
//    }
//public:
//    int _hp;
//    int _x;
//    int _y;
//};
//
//int main()
//{
//    // 유저 영역 [메모장]
//    //malloc
//    // - 할당할 메모리 크기를 건네준다.
//    // - 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다.(메모리 부족시 NULL)
//    // C++ 에서는 CRT(C 런타임 라이브러리)의 힙 관리자를 통해 힙 영역 사용
//    // free
//    // - malloc( calloc realloc 등의 사촌) 을 통해 할당된 영역을 해제
//    // - 힙 관리자가 할당/미할당 여부를 관리하기 때문에 쓸 수 있다.
//    void* pointer = malloc(sizeof(Monster));
//    Monster* m1 = (Monster*)pointer;
//    m1->_hp = 100;
//    m1->_x = 1;
//    m1->_y = 2;
//
//    //Heap Overflow
//    // - 유효한 힙 범위를 초과해서 사용하는 문제
//    // ex) 4바이트 할당하고 Monster 넣어버리기
//    free(pointer);//안할경우 Memory leak가 발생
//    //free하면 몇바이트 할당했는지 힌트가 있었는데 그것까지 날아감
//    //Double Free
//    // 대부분 크래시 나고 끝남
//    //free(pointer);
//
//    // Use- After - Free
//    // 댕글링 포인터 메모리는 free가 되었지만 pointer에 접근이 가능하다.
//    // 나비 효과로 메모리가 오염될 수도 있음
//    pointer = nullptr;
//    m1 = nullptr;
//
//    Monster* m2 = new Monster;
//    m2->_hp = 200;
//    m2->_x = 2;
//    m2->_y = 3;
//    delete m2;
//    m2 = nullptr;
//
//    int count = 3;
//    Monster* m3 = new Monster[count];
//    Monster* m4 = (m3 + 1);
//    delete[] m3; // <- 짝을 잘 맞춰야한다. malloc/free new/delete, new[]/delete[]
//    m3 = nullptr;
//    m4 = nullptr;
//    return 0;
//}

#pragma endregion
#pragma region 타입 변환
//malloc -> void*을 반환하고 이를 우리가 (타입 변환)을 통해 사용했었음
class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	//타입 변환 생성자
	Dog(const Knight& knight)
	{
		_age = knight._hp;
	}
public:
	int _age = 1;
	int _cuteness = 2;
};

int main()
{
	// 타입 변환 유형(비트열 재구성 여부)
	// [1] 값 타입 변환
	// 특징) 의미를 유지하기 위해서, 원본 객체와 다른 비트열 재구성
	int a = 123456789; // 2의 보수
	float b = (float)a; // 부동소수점(지수 + 유효숫자)
	cout << b << endl;

	//[2] 참조 타입 변환
	// 특징) 비트열을 재구성하지 않고, '관점'만 바꾸는 것
	// 포인터 타입 변환도 참조 타입변환 동일한 룰을 따름
	a = 123456789;
	b = (float&)a;//데이터는 유지하지만 float 관점에서 a를 바라본것
	cout << b << endl;

	// -------- 안전도 분류 -----------

	// [1] 안전한 변환
	// 특징) 의미가 항상 100% 완전히 일치하는 경우
	// 같은 타입이면서 크기만 더 큰 바구니로 이동
	// 작은 바구니 -> 큰 바구니로 이동 OK(업캐스팅)
	// ex) char -> short, short -> int, int->_int64
	a = 123456789;
	_int64 c = a;
	cout << c << endl;

	// [2] 불안전한 변환
	// 특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우
	// 타입이 다르거나
	// 같은 타입이지만 큰 바구니 -> 작은 바구니 이동 (다운캐스팅)
	a = 123456789;
	float d = a;
	short f = a;
	cout << d << endl;
	cout << f << endl;

	// ------------ 프로그래머 의도에 따라 분류 ----------------

	//[1] 암시적 변환
	// 특징) 이미 알려진 타입 변환 규칙에 따라서 컴파일러 '자동'으로 타입변환
	a = 123456789;
	float e = a;//암시적으로 변환

	//[2] 명시적 변환
	a = 123456789;
	int* L = (int*)a;// 명시적으로 변환
	cout << L << endl;

	// ------------- 아무런 연관 관계가 없는 클래스 사이의 변환 ---------
	//[1] 연관 없는 클래스 사이의 '값 타입' 변환
	// 특징) 일반적으로 안 됨(예외 : 타입 변환 생성자, 타입 변환 연산자)
	{
		Knight knight;
		Dog dog = (Dog)knight;//암시적 명시적 둘 다 불가
	}
	return 0;
}
#pragma endregion
