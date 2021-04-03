#include <iostream>
using namespace std;

//class Knight
//{
//public:
//	//생성자
//	Knight()
//	{
//		cout << "Knight 기본 생성자 출력" << endl;
//	}
//	//복사생성자
//	//일반적으로 '똑같은' 데이터를 가진 객체가 생성되길 기대함
//	Knight(const Knight& knight)
//	{
//		hp = knight.hp;
//		attack = knight.attack;
//		posX = knight.posX;
//		posY = knight.posY;
//	}
//
//	//인자를 1개만 받는 기타 생성자를 타입변환생성자
//	// 명시적 용도로만 사용할 것!
//	explicit Knight(int hp)
//	{
//		this->hp = hp;
//	}
//	//소멸자
//	~Knight()
//	{
//		cout << "Knight 소멸자 출력" << endl;
//	}
//
//    //멤버 함수
//    void Move(int y, int x);
//    void Attack();
//	void HelloKnight(Knight knight)
//	{
//		cout << "Hello Knight" << endl;
//	}
//    void Die()
//    {
//        hp = 0;
//        cout << "Die" << endl;
//    }
//
//public:
//    //멤버 변수
//    int hp;
//    int attack;
//    int posY;
//    int posX;
//    
//};
//
//void Knight::Move(int y, int x)
//{
//    posY = y;
//    posX = x;
//    cout << "Move" << endl;
//}
//
//void Knight::Attack()
//{
//
//}
//
////Instantiate 객체를 만든다!
//
//
//int main()
//{
//    Knight k1;
//    k1.hp = 100;
//    k1.attack = 10;
//    k1.posY = 0;
//    k1.posX = 0;
//
//	Knight k2(k1);
//	Knight k3 = k1;//복사생성자로 생성
//	
//	Knight k4;//기본생성자로 생성 후 복사
//	k4 = k1;//k3와 k4의 생성방식이 다름
//	Knight k5 = (Knight)1;// <- Knight(int hp)호출로 생성 명시적으로 변환하도록 선언
//	k5.HelloKnight((Knight)10);//Knight(int hp) 10 인 아이가 생성
//}

//객체지향 Object Oriented Programming
//OOP
//상속성
//은닉성 public  protected private
//다형성
#pragma region 상속성 part
//class Player
//{
//public:
//	Player()
//	{
//		cout << "Player 생성자 호출" << endl;
//	}
//	Player(int hp)
//	{
//		cout << "Player hp 생성자 호출" << endl;
//	}
//	~Player()
//	{
//		cout << "Player 소멸자 호출" << endl;
//	}
//	void Move() { cout << "Player Move 호출" << endl; }
//	void Attack() { cout << "Player Attack 호출" << endl; }
//	void Die() { cout << "Player Die 호출" << endl; }
//public:
//	int _hp;
//	int _attack;
//	int _defence;
//};
//
//class Knight : public Player
//{
//public:
//	Knight()
//	{
//		cout << "Knight 생성자 호출" << endl;
//	}
//	Knight(int stamina) : Player(100)
//	{
//		cout << "Knight Stamina 생성자 호출" << endl;
//	}
//	~Knight()
//	{
//		cout << "Knight 소멸자 호출" << endl;
//	}
//	void Move()
//	{
//		cout << "Knight Move 호출" << endl;
//	}
//public:
//	int _stamina;
//};
//
//class Mage : public Player
//{
//public:
//	int _mp;
//};
//int main()
//{
//	Knight k;
//	k._hp = 100;
//	k._attack = 10;
//	k._defence = 5;
//	k._stamina = 100;
//	k.Move();
//	k.Player::Move();
//	//k.Attack();
//	//k.Die();
//	return 0;
//}
#pragma endregion

class Car
{
public:
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		RunEngine();
	}
protected:
	void DisassembleCar() {}
	void RunEngine() {}
	void ConnectCircuit(){}
};


//상속 접근 지정자 : 다음세대에게 부모 성질 어떻게 물려줄지
// public : 부모 유산 그대로 설계 상속(public -> public, protected -> protected)
// protected : 자손들에게만 상속(public -> protected, protected -> protected)
// private : 개인적인 상속(public -> private, protected -> private)
class SuperCar : public Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

//캡슐화
class Berserker
{
public:
	int GetHp() { return _hp; }
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}
private:
	void SetBerserkerMode()
	{
		cout << "매우 강해짐" << endl;
	}
private:
	int _hp;
};

int main()
{
	Car car;
	return 0;
}