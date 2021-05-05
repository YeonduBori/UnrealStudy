#include <iostream>
using namespace std;
#include <vector>
#include <list>
#pragma region auto
////오늘의 주제 auto
//int main()
//{
//    //Modern C++ (C++ 11)
//
//    int a = 3;
//    const auto test5309 = a;
//    auto* test = "auto pointer to const char";
//    //기본 auto는 const, & 무시
//    int& referrence = a;
//    const int cst = a;
//    auto test1 = referrence;// int 가 됨 참조형이 아님
//    auto test2 = cst; // const int인데 int가 되어버림
//
//    vector<int> v;
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//
//    for (vector<int>::size_type i = 0; i < v.size(); i++)
//    {
//        auto& data = v[i];//참조형이 아닌 int가 되어버림
//        data = 100;
//    }
//    return 0;
//
//}

#pragma endregion

#pragma region 중괄호 초기화
//class Knight
//{
//public:
//public:
//	Knight()
//	{
//
//	}
//
//	Knight(initializer_list<int> li)//중괄호 초기화시 이 생성자 우선순위가 매우 강력하게 적용
//	{
//		cout << "Knight(initializer_list)" << endl;
//	}
//};
//int main()
//{
//	//중괄호 초기화 {}
//	int a = 0;
//	int b(0);
//	int c{ 0 };
//
//	Knight k1;
//	Knight k2 = k1;//복사 생성자 (대입 연산자 X)
//	Knight k3{ k1 };
//	Knight k4; //기본 생성자
//	k4 = k1; //대입 연산자
//	
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//
//	vector<int> v2(10, 1); // 1이 10개
//
//	vector<int> v3{ 1,2,3,4 };//배열 중괄호 초기화처럼 동작
//	//Container와 잘 어울린다.
//
//	// 축소 변환 방지
//	int x = 0;
//	double y{ x };//에러일으킴 축소변환을 막기 때문
//
//	//
//	Knight k4{};
//
//	Knight k5{ 1,2,3,4,5 };
//	return 0;
//}
#pragma endregion

#pragma region nullptr
//void Test(int a)
//{
//	cout << "Test(int a)" << endl;
//}
//
//void Test(void* ptr)
//{
//	cout << "Test(*)" << endl;
//}
//
//class Knight
//{
//public:
//};
//
//Knight* FindKnight()
//{
//	return nullptr;
//}
//
//class NullPtr
//{
//public:
//	// 그 어떤 타입의 포인터와도 치환 가능
//	template<typename T>
//	operator T* () const
//	{
//		return 0;
//	}
//
//	//그 어떤 타입의 멤버 포인터와도 치환 가능
//	template <typename C, typename T>
//	operator T C::* () const
//	{
//		return 0;
//	}
//
//private:
//	void operator&() const; // 주소값 &을 막는다.
//};
//
//const NullPtr _NullPtr;
//
//int main()
//{
//	int* ptr = nullptr;
//	ptr = NULL; // 둘 다 0값이 들어가긴 한다.
//
//	Test(0);// int 형태로 인식
//	Test(NULL);// int 형태로 인식
//	Test(nullptr);// 포인터 형태로 인식
//
//	auto knight = FindKnight();
//	if (knight == nullptr)
//	{
//
//	}
//	return 0;
//}
#pragma endregion

#pragma region using
////가독성 장점
//typedef vector<int>::iterator VecIt;
////1)직관성
//typedef void (*MyFunc)(); //함수형 포인터 선언
//using MyFunc2 = void(*)();
////2)템플릿
//template<typename T>
//using List = std::list<T>
//
//template<typename t>
//typedef std::vector<T> List2;
#pragma endregion

#pragma region enum class
//// unscoped enum
//enum PlayerType : char//char 형태로 가능
//{
//	PT_Knight,
//	PT_Archer,
//	PT_Mage
//};
//
//enum MonsterType
//{
//	MT_Knight// 이름 겹치면 안됨
//};
//
//enum class ObjectType
//{
//	Player,
//	Monster,
//	Projectile
//};
//
//int main()
//{
//	// enum class(scoped enum)
//	// 1) 이름공간 관리 (scoped)
//	// 2) 암묵적인 변환 금지
//	ObjectType type = ObjectType::Player;// C#의 enum과 동일
//	return 0;
//}
#pragma endregion

#pragma region delete(삭제된함수)
//
//class Knight
//{
//public:
//private:
//	// 정의되지 않은 비공개(private) 함수
//public:
//	void operator=(const Knight& k) = delete;
//	friend class Admin;
//private:
//	int _hp = 100;
//};
//
//class Admin
//{
//public:
//	void CopyKnight(const Knight& k)
//	{
//		Knight k1;
//		k1 = k;
//	}
//};
//
//int main()
//{
//	Knight k1;
//
//	Knight k2;
//
//	//k1 = k2;
//	return 0;
//}
#pragma endregion

#pragma region override final
//class Creature
//{
//public:
//	virtual void Attack()
//	{
//		cout << "Creature!" << endl;
//	}
//};
//class Player : public Creature
//{
//public:
//	virtual void Attack() final//오버라이드를 막는다.
//	{
//		cout << "Player!" << endl;
//	}
//};
//
//class Knight : public Player
//{
//public:
//
//	//virtual void Attack() const//const가 붙으면 멤버를 수정하지 않겠다는 의미, 가상함수여도 최초로 정의한 함수처럼 됨
//	//{
//	//	cout << "Knight" << endl;
//	//}
//	//재정의(override)
//	virtual void Attack() override
//	{
//		cout << "Knight" << endl;
//	}
//	//// 오버로딩 함수 이름의 재사용?
//	//void Attack(int a)
//	//{
//	//	cout << "Knight" << a << endl;
//	//}
//};
//int main()
//{
//	Player* player = new Knight();
//	Knight* knight = new Knight();
//
//	player->Attack();
//	knight->Attack();
//	return 0;
//}
#pragma endregion

#pragma region Rvalue 참조와 std::move
//class Knight
//{
//public:
//	Knight()
//	{
//		cout << "Knight" << endl;
//	}
//	Knight(const Knight& knight)
//	{
//		cout << "const Knight&" << endl;
//	}
//	//이동 생성자
//	//이동 대입 연산자
//	void operator=(Knight&& knight) noexcept
//	{
//		cout << "operator=(Knight&&)" << endl;
//	}
//public:
//	int _hp = 100;
//};
//
//void TestKnightCopy(Knight knight){ }
//void TestKnightCopy_LValueRef(Knight& knight){ }
//void TestKnightCopy_ConstLValueRef(const Knight& knight){ }
//void TestKnightCopy_RValueRef(Knight&& knight){ } // 이동 대상
//
//int main()
//{
//	// 왼값(lvalue) vs 오른값(rvalue)
//	// - lvalue : 단일식을 넘어서 계속 지속되는 개체
//	// - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)
//	
//	//int a = 3;
//	//3 = a;
//
//	Knight k1;
//
//	TestKnightCopy(k1);//복사 연산이 되어 k1과 복사된 knight와 연관 X
//	TestKnightCopy_LValueRef(k1);
//	TestKnightCopy_ConstLValueRef(Knight());
//
//	TestKnightCopy_RValueRef(Knight());
//	return 0;
//}
#pragma endregion

#pragma region 람다 lambda
//// 함수 객체를 빠르게 만드는 방법
//
//enum class ItemType
//{
//	None,
//	Armor,
//	Weapon,
//	Jewelry,
//	Comsumable
//};
//
//enum class Rarity
//{
//	Common,
//	Rare,
//	Unique
//};
//
//class Item
//{
//public:
//	Item(){}
//	Item(int itemId, Rarity rarity, ItemType type)
//		: _itemId(itemId), _rarity(rarity), _type(type)
//	{
//
//	}
//
//	auto ResetItemJob()
//	{
//		auto Reset = [this]()
//		{
//			this->_itemId = 0;
//		};
//
//		return Reset;
//	}
//public:
//	int _itemId = 0;
//	Rarity _rarity = Rarity::Common;
//	ItemType _type = ItemType::None;
//};
//
//int main()
//{
//	vector<Item> v;
//	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
//	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
//	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
//	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));
//
//	// 람다 = 함수 객체를 손쉽게 만드는 문법
//	// 람다 자체로 C++ 11에 '새로운' 기능이 들어간 것은 아니다.
//	{
//		struct IsUniqueItem
//		{
//			bool operator()(Item& item)
//			{
//				return item._rarity == Rarity::Unique;
//			}
//		};
//
//		struct FindByItemID
//		{
//			FindByItemID(int itemId):_itemId(itemId)
//			{
//
//			}
//
//			bool operator()(Item& item)
//			{
//				return item._itemId == _itemId;
//			}
//
//			int _itemId;
//		};
//		int itemId = 4;
//		Rarity rarity = Rarity::Unique;
//		ItemType type = ItemType::Weapon;
//
//		auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; };//람다 표현식
//		auto findItemIt = find_if(v.begin(), v.end(), FindByItemID(2));
//		auto findIt = find_if(v.begin(), v.end(), IsUniqueItem());
//
//		// 대괄호에 &냐 = 에 따라 참조형태로 쓰냐 값복사로 쓰냐가 달라짐
//		auto findByItem = [&](Item& item)
//		{
//			return item._itemId == itemId && item._rarity == rarity && item._type == type;
//		};
//
//		// 가독성 측면에서 안에 변수를 적어주는 것이 좋다.
//		// 3개라면 ItemId, &rarity &type 이런식으로 
//		// 특정 변수만 참조형태로 지정도 가능
//		//auto findByItem = [&itemId](Item& item)
//		//{
//		//	return item._itemId == itemId && item._rarity == rarity && item._type == type;
//		//};
//		// 예외적용도 가능 itemId를 제외한 나머지는 값복사 형태
//		//auto findByItem = [= ,&itemId](Item& item)
//		//{
//		//	return item._itemId == itemId && item._rarity == rarity && item._type == type;
//		//};
//		findIt = find_if(v.begin(), v.end(), isUniqueLambda);
//		if (findIt != v.end())
//			cout << "아이템 ID : " << findIt->_itemId << endl;
//		if(findItemIt != v.end())
//			cout << "아이템 ID : " << findItemIt->_itemId << endl;
//	}
//	return 0;
//}
#pragma endregion

#pragma region Smart Pointer
class Knight
{
public:
	Knight() { cout << "Knight 생성" << endl; }
	~Knight() { cout << "Knight 소멸" << endl; }
	void Attack()
	{
		if(_target)
		{
			_target->_hp -= _damage;
			cout << "HP : " << _target->_hp << endl;
		}
	}
public:
	int _hp = 100;
	int _damage = 10;
	shared_ptr<Knight> _target = nullptr;
};

//참조 카운트 관리
class RefCountBlock
{
public:
	int _refCount = 1;
};
template<typename T>
class SharedPtr
{
public:
	SharedPtr() {}
	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock();
			cout << "Ref Count : " << _block->_refCount << endl;
		}
	}
	SharedPtr(const SharedPtr& sptr):_ptr(sptr._ptr),_block(sptr._block)
	{
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "Ref Count : " << _block->_refCount << endl;
		}
	}

	void operator =(const SharedPtr& sptr)
	{
		_ptr = sptr._ptr;
		_block = sptr._block;

		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "Ref Count : " << _block->_refCount << endl;
		}
	}
	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "Ref Count : " << _block->_refCount << endl;
			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}
public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};

int main()
{
	//Knight* k1 = new Knight();
	//Knight* k2 = new Knight();
	//k1->_target = k2;
	//delete k2;
	//k1->Attack();
	// 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체(포인터를 래핑해서 사용)
	// shared_ptr, weak_ptr, unique_ptr
	//SharedPtr<Knight> k1(new Knight());
	//SharedPtr<Knight> k2 = k1;

	shared_ptr<Knight> k1 = make_shared<Knight>();
	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->_target = k2;
		k2->_target = k1;
		//이 같은 순환참조 조심
		//메모리가 해제되지 않는다.
	}

	k1->Attack();

	return 0;
}
#pragma endregion
