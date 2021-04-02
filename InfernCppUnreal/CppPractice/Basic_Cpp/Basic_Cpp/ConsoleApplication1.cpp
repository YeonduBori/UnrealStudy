#include <iostream>
using namespace std;

//데이터 + 가공 = 프로그램

class Knight
{
public:
	//생성자
	Knight()
	{
		cout << "Knight 기본 생성자 출력" << endl;
	}
	//복사생성자
	//일반적으로 '똑같은' 데이터를 가진 객체가 생성되길 기대함
	Knight(const Knight& knight)
	{
		hp = knight.hp;
		attack = knight.attack;
		posX = knight.posX;
		posY = knight.posY;
	}

	//인자를 1개만 받는 기타 생성자를 타입변환생성자
	// 명시적 용도로만 사용할 것!
	explicit Knight(int hp)
	{
		this->hp = hp;
	}
	//소멸자
	~Knight()
	{
		cout << "Knight 소멸자 출력" << endl;
	}

    //멤버 함수
    void Move(int y, int x);
    void Attack();
	void HelloKnight(Knight knight)
	{
		cout << "Hello Knight" << endl;
	}
    void Die()
    {
        hp = 0;
        cout << "Die" << endl;
    }

public:
    //멤버 변수
    int hp;
    int attack;
    int posY;
    int posX;
    
};

void Knight::Move(int y, int x)
{
    posY = y;
    posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{

}

//Instantiate 객체를 만든다!


int main()
{
    Knight k1;
    k1.hp = 100;
    k1.attack = 10;
    k1.posY = 0;
    k1.posX = 0;

	Knight k2(k1);
	Knight k3 = k1;//복사생성자로 생성
	
	Knight k4;//기본생성자로 생성 후 복사
	k4 = k1;//k3와 k4의 생성방식이 다름
	Knight k5 = (Knight)1;// <- Knight(int hp)호출로 생성 명시적으로 변환하도록 선언
	k5.HelloKnight((Knight)10);//Knight(int hp) 10 인 아이가 생성
}