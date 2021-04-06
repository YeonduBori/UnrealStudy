#include <iostream>
using namespace std;

#pragma region 초기화 리스트 필요성
/*
//초기화 방법
// - 생성자 내부에서
// - 초기화 리스트
// - C++ 11문법

//초기화 리스트
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다.
// -- 정의함과 동시에 초기화가 필요한 경우(참조 타입, const 타입)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; }
	~Inventory() { cout << "~Inventory()" << endl; }
public:
	int _size = 10;
};

class Player
{
public :
	Player(){}
	Player(int id) {}
};

// Is - A (Knight Is-A Player? 기사는 플레이어다) OK? -> 상속관계
// Has - A (Knight Has-A Inventory? 기사는 인벤토리를 갖고있다) -> 포함관계

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20),
		_hpRef(_hp), _hpConst(100)
		
		//선처리 영역...
		//Inventory()
	{
	}
public:
	int _hp;
	Inventory _inventory;

	int& _hpRef;// 문법 설명을 위한 변수들
	const int _hpConst;
};


int main()
{
	Knight k;
	cout << k._hp << endl;
	if (k._hp < 0)
	{
		cout << "Knight is Dead!" << endl;
	}
	return 0;
}
*/
#pragma endregion

#pragma region 연산자 오버로딩
//연산자 vs 함수
// - 연산자는 피연산자의 개수/타입이 고정되어 있음
// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야함
// 함수도 멤버함수 vs 전역함수가 존재하는 것처럼, 연산자 함수도 두가지 방식으로 만들 수 있음


// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽으로 기준으로 실행됨(a가 클래스여야 가능, a를 '기준 피연산자'라고 함)
// -- 한계) a가 클래스가 아니면 사용 못함

// - 전역 연산자 함수 version
// -- a op b형태라면 a,b 모두를 

// 복사 대입 연산자 = 대입연산자 중, 자기자신의 참조 타입을 인자로 받는것

//기타
//모든 연산자를 다 오버로딩 할 수 있는 것은 아니다.(:: . .* 이런건 안됨)
// 모든 연산자가 다 2개 항이 있는건 아님 ++ -- 대표적(단항 연산자)
// 증감연산자 ++ --
//-- 전위형 ++a operator++()
//-- 후위형 a++ operator++(int)

class Position
{
public:
	//값복사가 아닌 참조 형태로 효율성 개선
	//const 선언으로 원본 수정 불가하게 블락
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	Position& operator=(Position& arg)
	{
		_x = arg._x;
		_y = arg._y;
		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	void operator++(int)
	{
		_x++;
		_y++;
	}
	Position& operator =(int arg)
	{
		_x = arg;
		_y = arg;
		return *this;
	}
public:
	int _x;
	int _y;
};

Position operator + (int a, const Position& b)
{
	Position ret;
	ret._x = b._x + a;
	ret._y = b._y + a;
	return ret;
}

//void operator =(const Postion& a ,int arg)
//{
//	a._x = arg;
//	a._y = arg;
//}

int main()
{
	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;
	//pos3 = pos.operator+(pos2);
	Position pos4 = 1 + pos3;

	bool isSame = (pos3 == pos4);
	
	Position pos5; //= 5;//타입변환생성자(int something = 5)를 호출
	pos3 = (pos5 = 5);//기본 생성자 호출 후 operator =을 통해 x 5 y 5
	return 0;
}
#pragma endregion