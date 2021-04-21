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
// typedef의 진실
// typedef 왼쪽 오른값 -> 오른쪽 (커스텀 타입 정의)
// 정확히는 왼쪽/오른쪽 기준이 아니라
// [선언 문법]에서 typedef을 앞에다 붙이는 쪽
class Knight
{
public:
	int GetHP(int, int)
	{
		cout << "Get HP" << endl;
		return 1;
	}
};

typedef int(*PFUNC)(int, int);
typedef int(Knight::*PMEMFUNC)(int, int);

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a+b;
}

int main()
{
	//int (*fn)(int, int);

	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;
	PFUNC fn;
	fn = Test;
	fn = &Test;// & 생략 가능 (C언어 호환성 떄문)
	fn(1, 2);
	(*fn)(1, 2);
	// 위의 방법으로는 전역함수 / 정적 함수 만 담을 수 있다. (호출 규약이 동일한 애들)
	Knight k1;
	k1.GetHP(1, 1);
	PMEMFUNC mfn;
	mfn = &Knight::GetHP;
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	((*k2).*mfn)(1, 1);
	(k2->*mfn)(1, 1);
	delete k2;
}
#pragma endregion