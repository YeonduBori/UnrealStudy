#include <iostream>

using namespace std;

enum HandType
{
	SCISSORS = 0,
	ROCK,
	PAPER
};

#define DEFINE_SCISSORS 1//전처리기 1)전처리 2)컴파일 3)링크
//#include -> 컴파일 전에 iostream 파일을 찾아서 해당 내용을 복붙

//함수의 시그니처 선언
void Func1();
void Func2(int a, int b);
void Func3(float);//이 형태도 가능

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
	#pragma region Region 나누기
	HandType playerHand = SCISSORS;
	//cpp에선 unsigned char 이용하여 비트 플래그 사용
	#pragma endregion

	Func1();
}