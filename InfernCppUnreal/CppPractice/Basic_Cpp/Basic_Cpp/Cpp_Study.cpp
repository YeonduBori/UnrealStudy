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

int main()
{
	#pragma region Region ������
	HandType playerHand = SCISSORS;
	//cpp���� unsigned char �̿��Ͽ� ��Ʈ �÷��� ���
	#pragma endregion
}