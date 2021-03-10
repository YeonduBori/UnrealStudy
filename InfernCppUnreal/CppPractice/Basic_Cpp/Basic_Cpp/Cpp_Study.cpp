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

int main()
{
	#pragma region Region 나누기
	HandType playerHand = SCISSORS;
	//cpp에선 unsigned char 이용하여 비트 플래그 사용
	#pragma endregion
}