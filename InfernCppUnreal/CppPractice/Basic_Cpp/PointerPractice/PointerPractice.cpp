#include <iostream>
using namespace std;

struct Player
{
	int hp;
	int damage;
};

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo* player, StatInfo* monster);

void EnterLobby()
{
	cout << "로비에 입장했습니다." << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;
	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;
	CreateMonster(&monster);

	StartBattle(&player, &monster);
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;
		
		player->hp -= damage;
		cout << "플레이어 HP : " << player->hp << endl;
	}
}

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
	//int number = 1;
	//int* pointer = &number;

	//number += 1;
	//
	////pointer += 1;
	////한번의 타입의 크기만큼 이동하라
	////다음 or 이전 바구니 단위의 이동

	////간접 연산자
	//*pointer = 3;
	//cout << number << endl;

	//Player player;
	//player.hp = 100;
	//player.damage = 200;

	//Player* ptrPlayer = &player;
	//(*ptrPlayer).hp = 200;
	//(*ptrPlayer).damage = 300;
	//ptrPlayer->hp = 100;// *. 합친게 ->
#pragma endregion

#pragma region 포인터 실습
	EnterLobby();
#pragma endregion
	return 0;
}