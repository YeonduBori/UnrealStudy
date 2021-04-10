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
////malloc -> void*을 반환하고 이를 우리가 (타입 변환)을 통해 사용했었음
//class Knight
//{
//public:
//	int _hp = 10;
//};
//
//class Dog
//{
//public:
//	Dog()
//	{
//
//	}
//	//타입 변환 생성자
//	Dog(const Knight& knight)
//	{
//		_age = knight._hp;
//	}
//
//	operator Knight()
//	{
//		return (Knight)(*this);
//	}
//public:
//	int _age = 1;
//	int _cuteness = 2;
//};
//
//class BullDog : public Dog
//{
//public:
//	bool _french;
//};
//
//int main()
//{
//	// 타입 변환 유형(비트열 재구성 여부)
//	// [1] 값 타입 변환
//	// 특징) 의미를 유지하기 위해서, 원본 객체와 다른 비트열 재구성
//	int a = 123456789; // 2의 보수
//	float b = (float)a; // 부동소수점(지수 + 유효숫자)
//	cout << b << endl;
//
//	//[2] 참조 타입 변환
//	// 특징) 비트열을 재구성하지 않고, '관점'만 바꾸는 것
//	// 포인터 타입 변환도 참조 타입변환 동일한 룰을 따름
//	a = 123456789;
//	b = (float&)a;//데이터는 유지하지만 float 관점에서 a를 바라본것
//	cout << b << endl;
//
//	// -------- 안전도 분류 -----------
//
//	// [1] 안전한 변환
//	// 특징) 의미가 항상 100% 완전히 일치하는 경우
//	// 같은 타입이면서 크기만 더 큰 바구니로 이동
//	// 작은 바구니 -> 큰 바구니로 이동 OK(업캐스팅)
//	// ex) char -> short, short -> int, int->_int64
//	a = 123456789;
//	_int64 c = a;
//	cout << c << endl;
//
//	// [2] 불안전한 변환
//	// 특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우
//	// 타입이 다르거나
//	// 같은 타입이지만 큰 바구니 -> 작은 바구니 이동 (다운캐스팅)
//	a = 123456789;
//	float d = a;
//	short f = a;
//	cout << d << endl;
//	cout << f << endl;
//
//	// ------------ 프로그래머 의도에 따라 분류 ----------------
//
//	//[1] 암시적 변환
//	// 특징) 이미 알려진 타입 변환 규칙에 따라서 컴파일러 '자동'으로 타입변환
//	a = 123456789;
//	float e = a;//암시적으로 변환
//
//	//[2] 명시적 변환
//	a = 123456789;
//	int* L = (int*)a;// 명시적으로 변환
//	cout << L << endl;
//
//	// ------------- 아무런 연관 관계가 없는 클래스 사이의 변환 ---------
//	//[1] 연관 없는 클래스 사이의 '값 타입' 변환
//	// 특징) 일반적으로 안 됨(예외 : 타입 변환 생성자, 타입 변환 연산자)
//	{
//		Knight knight;
//		Dog dog = (Dog)knight;//암시적 명시적 둘 다 불가
//		Knight knight2 = dog;
//	}
//	//[2] 연관 없는 클래스 사이의 참조 타입 변환
//	//특징) 명시적으로는 OK
//	{
//		Knight knight;
//		//왜 통과?
//		//어셈블리 관점에서 보면 어셈블리 : 포인터 = 참조
//		// [ 주소 ] -> [ Dog ] 주소에 Dog이 있다고 주장
//		// 그래서 거짓이라 하더라도 변환 자체는 통과될 수 있다. 
//		Dog& dog = (Dog&)knight;
//		dog._cuteness = 12;//건들면 안되는 메모리를 건듦
//	}
//	// --------------- 상속 관계에 있는 클래스 사이의 변환 -------------------
//	// 자식 -> 부모 OK / 부모 -> 자식 NO
//	// [1] 상속 관계 클래스의 값 타입 변환
//	{
//		//Dog dog;
//		//BullDog bullDog = dog;//모든 개는 불독일 수 없다. 명시 암시 둘 다 불가
//
//		BullDog bullDog;
//		Dog dog = bullDog; // french를 제외한 나머지 정보만 Dog로 들어감
//	}
//	
//	// [2] 상속 관계 클래스의 참조타입변환
//	{
//		//Dog dog;
//		//BullDog& bullDog = (BullDog&)dog;
//
//		BullDog bullDog;
//		Dog& dog = bullDog;
//	}
//
//	//결론)
//	// [값 타입 변환] : 진짜 비트열도 바꾸고 - 논리적으로 말이 되게 바꾸는 변환
//	// - 논리적으로 말이 된다? (ex BullDog -> Dog ) OK
//	// - 논리적으로 말이 안 된다.(Dog -> BullDog, Dog -> Knight) 안됨
//	// [참조 타입 변환] : 비트열은 냅두고 우리의 '관점'만 바꾸는 변환
//	// 땡깡 부리면 해주긴 하는데, 말 안 해도 '그냥' 암시적으로 해주는지는 안전성 여부가 연관되어있음
//	// 안전하다 (BullDog -> Dog& 암시적으로 그냥 OK)
//	// 위험하다 (Dog -> BullDog&)
//	// 메모리 침범 위험이 있는 경우는 암시적으로 해주진 않음 위험해서(메모리 침범)
//	// 명시적으로 정말 하겠다고 최종 서명을 하면 OK
//
//	return 0;
//}
#pragma endregion

#pragma region 타입 변환(포인터)
class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Itme&)" << endl;
	}

	~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;
	char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}
int main()
{
	//복습
	{
		//Stack메모리에 올라가있는 상태 Stack[ type(4) dbid(4) dummy(4096)]
		Item item;
		// Stack 바구니 자체는 Stack에 생성 [ 주소(4-8) ] -> Heap 주소 [ type(4) dbid(4) dummy(4096)]
		Item* item2 = new Item();
		//// 메모리 누수(Memory Leak) -> 누적되면 메모리가 터질 위험이 있다.
		//delete item2;
		//item2 = NULL;

		TestItem(item);
		TestItem(*item2);

		TestItemPtr(&item);
		TestItemPtr(item2);
	}

	//배열
	{
		cout << "-----------------------------" << endl;
		//진짜 item 100개 스택 메모리에 올라와있음
		Item item3[100] = {};

		cout << "-----------------------------" << endl;
		// 아이템을 가리키는 바구니가 100개 실체가 없을 수도 있음
		Item* item4[100] = {};
	}
	return 0;
}
#pragma endregion
