#include <iostream>
using namespace std;

#pragma region Debug
//void Test2()
//{
//    int b = 0;
//}
//
//void Test1()
//{
//    int a = 5;
//
//    Test2();
//}
//
//int main()
//{
//    Test1();
//    cout << "Hello World!\n";
//}
#pragma endregion

#pragma region Function Pointer
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//class Item
//{
//public:
//	Item() : _itemId(0), _rarity(0), _ownerId(0)
//	{
//
//	}
//public:
//	int _itemId;
//	int _rarity;
//	int _ownerId;
//};
//
//typedef bool(ITEM_SELECTOR)(Item* item, int);
//
//Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
//{
//	for (int index = 0; index < itemCount; index++)
//	{
//		Item* item = &items[index];
//		if(selector(item, value)) 
//			return item;
//	}
//
//	return nullptr;
//}
//
//bool IsRareItem(Item* item, int value)
//{
//	return item->_rarity >= value;
//}
//
//bool IsOwnerItem(Item* item, int ownerId)
//{
//	return item->_ownerId == ownerId;
//}
//
//int main()
//{
//	typedef int(FUNC_TYPE)(int, int);
//
//	//1)포인터 *
//	//2)변수 이름 fn
//	//3)데이터 타입 함수 인자는 int, int 반환은 int
//	FUNC_TYPE* fn;
//
//	fn = Add;
//
//	int result = fn(1, 2);
//	result = (*fn)(1, 2); // 함수 포인터는 접근 연산자 * 붙어도 함수 주소!
//	fn = Sub;
//	result = (*fn)(3, 2);
//	cout << result << endl;
//
//	Item items[10] = {};
//	items[3]._rarity = 2;//RARE
//	Item* rareItem = FindItem(items, 10, IsRareItem, 2);
//	cout << rareItem->_rarity << endl;
//	return 0;
//}
#pragma endregion

#pragma region Function Pointer_2
//// typedef의 진실
//// typedef 왼쪽 오른값 -> 오른쪽 (커스텀 타입 정의)
//// 정확히는 왼쪽/오른쪽 기준이 아니라
//// [선언 문법]에서 typedef을 앞에다 붙이는 쪽
//class Knight
//{
//public:
//	int GetHP(int, int)
//	{
//		cout << "Get HP" << endl;
//		return 1;
//	}
//};
//
//typedef int(*PFUNC)(int, int);
//typedef int(Knight::*PMEMFUNC)(int, int);
//
//int Test(int a, int b)
//{
//	cout << "Test" << endl;
//	return a+b;
//}
//
//int main()
//{
//	//int (*fn)(int, int);
//
//	//typedef int(FUNC_TYPE)(int, int);
//	//FUNC_TYPE* fn;
//	PFUNC fn;
//	fn = Test;
//	fn = &Test;// & 생략 가능 (C언어 호환성 떄문)
//	fn(1, 2);
//	(*fn)(1, 2);
//	// 위의 방법으로는 전역함수 / 정적 함수 만 담을 수 있다. (호출 규약이 동일한 애들)
//	Knight k1;
//	k1.GetHP(1, 1);
//	PMEMFUNC mfn;
//	mfn = &Knight::GetHP;
//	(k1.*mfn)(1, 1);
//
//	Knight* k2 = new Knight();
//	((*k2).*mfn)(1, 1);
//	(k2->*mfn)(1, 1);
//	delete k2;
//}
#pragma endregion

#pragma region Function instance
//// 함수 객체
//void HelloWorld()
//{
//	cout << "Hello World" << endl;
//}
//
//void HelloNumber(int number)
//{
//	cout << "Hello Number " << number << endl;
//}
//
//class Knight
//{
//public:
//	void AddHP(int addHp)
//	{
//		_hp += addHp;
//	}
//private:
//	int _hp = 100;
//};
//
//class Functor
//{
//public:
//	void operator()()
//	{
//		cout << "Functor Test" << endl;
//		cout << _value << endl;
//	}
//
//	bool operator()(int num)
//	{
//		cout << "Functor Test" << endl;
//		_value += num;
//		cout << _value << endl;
//
//		return true;
//	}
//private:
//	int _value = 0;
//};
//
//class MoveTask
//{
//public:
//	void operator()()
//	{
//		//TODO
//		cout << "해당 좌표로 플레이어 이동" << endl;
//	}
//public:
//	int _playerId;
//	int _posX;
//	int _posY;
//};
//
//int main()
//{
//	//함수 객체 : 함수처럼 동작하는 객체
//	//함수 포인터 단점
//	void(*pfunc)(void);
//	pfunc = &HelloWorld;
//	(*pfunc)();
//	//함수 포인터 단점
//	// 1) 시그니처가 안 맞으면 사용할 수 없다.
//	// 2) 상태를 가질 수 없다.
//	// 함수처럼 동작하는 객체
//	// 연산자 오버로딩
//	Functor functor;
//	functor();//오
//	bool ret = functor(3);
//
//	//MMO에서 함수 객체를 사용하는 예시
//	// 클라 <-> 서버
//	// 서버 : 클라가 보내준 네트워크 패킷을 받아서 처리
//	// ex) 클라 : 나 (5,0) 좌표로 이동시켜줘
//	MoveTask task;
//	task._playerId = 100;
//	task._posX = 5;
//	task._posY = 0;
//
//	// 나중에 여유 될 때 일감을 실행한다.
//	task();
//	return 0;
//}
#pragma endregion

#pragma region Template
class Knight
{
public:
	void AddHP(int addHp)
	{
		_hp += addHp;
	}
	int _hp = 100;
};

ostream& operator <<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}
template<typename T>
void Print(T a)
{
	cout << a << endl;
}

template<>
void Print(Knight knight)
{
	cout << "Knight!!!!!!!!!" << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿
	Print(50.5f);
	Print("Hello World");
	Print<int>(10.3);

	Knight k1;
	Print(k1);
	return 0;
}
#pragma endregion