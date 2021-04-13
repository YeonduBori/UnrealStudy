#include <iostream>
using namespace std;

//얕은 복사 vs 깊은 복사
class Pet
{
public:
    Pet()
    {
        cout << "Pet()" << endl;
    }
    ~Pet()
    {
        cout << "~Pet()" << endl;
    }
    Pet(const Pet& pet)
    {
        cout << "Pet(const Pet&)" << endl;
    }

    Pet& operator= (const Pet& pet)
    {
        cout << "operator=(const Pet&)" << endl;
        return *this;
    }
};

class RabbitPet : public Pet
{

};

class TurtulePet : public Pet
{

};

class Player
{
public:
    Player()
    {
        cout << "Player()" << endl;
    }

    //복사 생성자
    Player(const Player& player)
    {
        cout << "Player(const Player&)" << endl;
    }

    Player& operator= (const Player& player)
    {
        cout << "operator=(const Player&)" << endl;
        _level = player._level;
        return *this;
    }

public:
    int _level = 0;
};

class Knight : public Player
{
public:
    Knight()
    {
       /* _pet = new Pet();*/
    }

    Knight(const Knight& knight): Player(knight), _pet(knight._pet)
    {
        cout << "Knight(const Knight& knight)" << endl;
        _hp = knight._hp;
        /*_pet = new Pet(*knight._pet);*/
    }

    Knight& operator= (const Knight& knight)
    {
        cout << "oprator=(const Knight& knight)" << endl;
        _hp = knight._hp;
        Player::operator=(knight);
        _pet = knight._pet;
        //_pet = new Pet(*knight._pet);
        return *this;
    }

    ~Knight()
    {
        //if(_pet)
        //    delete _pet;
    }
public:
    int _hp = 100;
    Pet _pet;
};

int main()
{
    Knight knight;// 기본생성자
    knight._hp = 200;

    //cout << "------------ 복사 생성자 -------------" << endl;
    //Knight knight2 = knight;//복사 생성자가 개입
    //Knight knight3(knight);

    Knight knight3;//기본 생성자
    cout << "------------ 복사 대입 연산자 ----------" << endl;
    knight3 = knight;//복사대입연산자를 이용해 복사

    // 복사 생성자 + 복사 대입 연산자
    // 둘 다 안 만들어주면 컴파일러가 암시적으로 만들어준다.

    // 컴파일러가 알아서 잘 만들어주니까 괜찮다? -> NO
    // 얕은 복사 [Shallow Copy]
    // 멤버 데이터를 비트열 단위로 똑같이 복사 (메모리 영역 값을 그대로 복사)
    // 포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일한 객체를 가리키는 상태가 됨
    //Stack : Knight[ hp 0x1000(pet의 주소)] - > Heap 0x1000 Pet [   ]
    //Stack : Knight2[ hp 0x1000(pet의 주소)]
    //Stack : Knight3[ hp 0x1000(pet의 주소)]

    // 깊은 복사 [Deep Copy]
    // 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다(원본 객체가 참조하는 대상까지 새로 만들어서 복사)
    // 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 됨
    //Stack : Knight[ hp 0x1000(pet의 주소)] - > Heap 0x1000 Pet [   ]
    //Stack : Knight2[ hp 0x2000(pet의 주소)] - > Heap 0x2000 Pet [   ]
    //Stack : Knight3[ hp 0x3000(pet의 주소)] - > Heap 0x3000 Pet [   ]

    //실험)
    // - 암시적 복사 생성자 Steps
    // 1) 부모 클래스가 있다면 부모클래스의 복사 생성자 호출
    // 2) 멤버 클래스(포인터가 아닌)의 복사 생성자 호출
    // 3) 멤버가 기본 타입일 경우 메모리 복사(얕은 복사 Shallow Copy) 
    // - 명시적 복사 생성자 Steps
    // 1) 부모 클래스의 기본 생성자 호출
    // 2) 멤버 클래스의 기본 생성자 호출
    // 
    // - 암시적 복사 대입 연산자 Steps
    // 1) 부모 클래스의 복사 대입 연산자 호출
    // 2) 멤버 클래스의 복사 대입 연산자 호출
    // 3) 멤버가 기본 타입일 경우 메모리 복사(얕은 복사 Shallow Copy)
    // - 명시적 복사 대입 연산자 Steps
    // 1) 알아서 해주는 거 없음

    //객체를 복사한다는 것은 두 객체의 값들을 일치시키려는 것
    // 따라서 기본적으로 얕은 복사(Shallow Copy)방식으로 동작
    return 0;
}
