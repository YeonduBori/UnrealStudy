#include <iostream>
using namespace std;

#pragma region �ʱ�ȭ ����Ʈ �ʿ伺
/*
//�ʱ�ȭ ���
// - ������ ���ο���
// - �ʱ�ȭ ����Ʈ
// - C++ 11����

//�ʱ�ȭ ����Ʈ
// - �ϴ� ��� ���迡�� ���ϴ� �θ� ������ ȣ���� �� �ʿ��ϴ�
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ ��� ���̰� ����.
// -- �����԰� ���ÿ� �ʱ�ȭ�� �ʿ��� ���(���� Ÿ��, const Ÿ��)

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

// Is - A (Knight Is-A Player? ���� �÷��̾��) OK? -> ��Ӱ���
// Has - A (Knight Has-A Inventory? ���� �κ��丮�� �����ִ�) -> ���԰���

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20),
		_hpRef(_hp), _hpConst(100)
		
		//��ó�� ����...
		//Inventory()
	{
	}
public:
	int _hp;
	Inventory _inventory;

	int& _hpRef;// ���� ������ ���� ������
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

#pragma region ������ �����ε�
//������ vs �Լ�
// - �����ڴ� �ǿ������� ����/Ÿ���� �����Ǿ� ����
// ������ �����ε�?
// �ϴ� [������ �Լ�]�� �����ؾ���
// �Լ��� ����Լ� vs �����Լ��� �����ϴ� ��ó��, ������ �Լ��� �ΰ��� ������� ���� �� ����


// - ��� ������ �Լ� version
// -- a op b ���¿��� �������� �������� �����(a�� Ŭ�������� ����, a�� '���� �ǿ�����'��� ��)
// -- �Ѱ�) a�� Ŭ������ �ƴϸ� ��� ����

// - ���� ������ �Լ� version
// -- a op b���¶�� a,b ��θ� 

// ���� ���� ������ = ���Կ����� ��, �ڱ��ڽ��� ���� Ÿ���� ���ڷ� �޴°�

//��Ÿ
//��� �����ڸ� �� �����ε� �� �� �ִ� ���� �ƴϴ�.(:: . .* �̷��� �ȵ�)
// ��� �����ڰ� �� 2�� ���� �ִ°� �ƴ� ++ -- ��ǥ��(���� ������)
// ���������� ++ --
//-- ������ ++a operator++()
//-- ������ a++ operator++(int)

class Position
{
public:
	//�����簡 �ƴ� ���� ���·� ȿ���� ����
	//const �������� ���� ���� �Ұ��ϰ� ���
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
	
	Position pos5; //= 5;//Ÿ�Ժ�ȯ������(int something = 5)�� ȣ��
	pos3 = (pos5 = 5);//�⺻ ������ ȣ�� �� operator =�� ���� x 5 y 5
	return 0;
}
#pragma endregion