#include <iostream>
using namespace std;

struct Player
{
	int hp;
	int damage;
};

int main()
{
#pragma region 포인터 기본
	//int number = 0;

	//int* ptr = &number;

	//int value1 = *ptr;
	//*ptr = 2;
	//__int64* ptr2 = (__int64*)&number;

	//*ptr2 = 0xAABBCCDDEEFF;
#pragma endregion

#pragma region 포인터 연산
	int number = 1;
	int* pointer = &number;

	number += 1;
	
	//pointer += 1;
	//한번의 타입의 크기만큼 이동하라
	//다음 or 이전 바구니 단위의 이동

	//간접 연산자
	*pointer = 3;
	cout << number << endl;

	Player player;
	player.hp = 100;
	player.damage = 200;

	Player* ptrPlayer = &player;
	(*ptrPlayer).hp = 200;
	(*ptrPlayer).damage = 300;
	ptrPlayer->hp = 100;// *. 합친게 ->
#pragma endregion
	return 0;
}