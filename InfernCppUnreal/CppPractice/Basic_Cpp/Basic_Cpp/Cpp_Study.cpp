#include <iostream>

using namespace std;

enum HandType
{
	SCISSORS = 0,
	ROCK,
	PAPER
};

#define DEFINE_SCISSORS 1//��ó���� 1)��ó�� 2)������ 3)��ũ
//#include -> ������ ���� iostream ������ ã�Ƽ� �ش� ������ ����

//�Լ��� �ñ״�ó ����
void Func1();
void Func2(int a, int b);
void Func3(float);//�� ���µ� ����

void Func1()
{
	cout << "Func1" << endl;
	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;
	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;
	cout << a + 0.1f << endl;
}

int main()
{
	#pragma region Region ������
	HandType playerHand = SCISSORS;
	//cpp���� unsigned char �̿��Ͽ� ��Ʈ �÷��� ���
	#pragma endregion

	Func1();
}