#include <iostream>
using namespace std;
#pragma region pointer
//struct Player
//{
//	int hp;
//	int damage;
//};
//

//
//void EnterLobby();
//StatInfo CreatePlayer();
//void CreateMonster(StatInfo* info);
//bool StartBattle(StatInfo* player, StatInfo* monster);
//
//void EnterLobby()
//{
//	cout << "로비에 입장했습니다." << endl;
//
//	StatInfo player;
//	player.hp = 0xbbbbbbbb;
//	player.attack = 0xbbbbbbbb;
//	player.defence = 0xbbbbbbbb;
//	player = CreatePlayer();
//
//	StatInfo monster;
//	monster.hp = 0xbbbbbbbb;
//	monster.attack = 0xbbbbbbbb;
//	monster.defence = 0xbbbbbbbb;
//	CreateMonster(&monster);
//
//	StartBattle(&player, &monster);
//}
//
//StatInfo CreatePlayer()
//{
//	StatInfo ret;
//
//	cout << "플레이어 생성" << endl;
//
//	ret.hp = 100;
//	ret.attack = 10;
//	ret.defence = 2;
//
//	return ret;
//}
//
//void CreateMonster(StatInfo* info)
//{
//	cout << "몬스터 생성" << endl;
//
//	info->hp = 40;
//	info->attack = 8;
//	info->defence = 1;
//}
//
//bool StartBattle(StatInfo* player, StatInfo* monster)
//{
//	while (true)
//	{
//		int damage = player->attack - monster->defence;
//		if (damage < 0)
//			damage = 0;
//
//		monster->hp -= damage;
//		if (monster->hp < 0)
//			monster->hp = 0;
//
//		cout << "몬스터 HP : " << monster->hp << endl;
//
//		if (monster->hp == 0)
//			return true;
//
//		damage = monster->attack - player->defence;
//		if (damage < 0)
//			damage = 0;
//
//		player->hp -= damage;
//		cout << "플레이어 HP : " << player->hp << endl;
//	}
//}
//
//int main()
//{
//#pragma region 포인터 기본
//	//int number = 0;
//
//	//int* ptr = &number;
//
//	//int value1 = *ptr;
//	//*ptr = 2;
//	//__int64* ptr2 = (__int64*)&number;
//
//	//*ptr2 = 0xAABBCCDDEEFF;
//#pragma endregion
//
//#pragma region 포인터 연산
//	//int number = 1;
//	//int* pointer = &number;
//
//	//number += 1;
//	//
//	////pointer += 1;
//	////한번의 타입의 크기만큼 이동하라
//	////다음 or 이전 바구니 단위의 이동
//
//	////간접 연산자
//	//*pointer = 3;
//	//cout << number << endl;
//
//	//Player player;
//	//player.hp = 100;
//	//player.damage = 200;
//
//	//Player* ptrPlayer = &player;
//	//(*ptrPlayer).hp = 200;
//	//(*ptrPlayer).damage = 300;
//	//ptrPlayer->hp = 100;// *. 합친게 ->
//#pragma endregion
//
//#pragma region 포인터 실습
//	EnterLobby();
//#pragma endregion
//	return 0;
//}
#pragma endregion

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};
StatInfo globalInfo;

void PrintInfo(StatInfo& info)
{
	cout << "hp : " << info.hp << endl;
	cout << "attack : " << info.attack << endl;
	cout << "defence : " << info.defence << endl;
	//info.hp = 100; <- error
}

void PrintInfo(StatInfo* info)
{
	if (info == nullptr)
		return; // NULL 체크

	cout << "hp : " << info->hp << endl;
	cout << "attack : " << info->attack << endl;
	cout << "defence : " << info->defence << endl;

	//별 뒤에 붙인다면
	// StatInfo * const info
	// info라는 바구니의 내용물(주소)를 바꿀 수 없음
	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다.
	// info = &globalInfo; <- error

	//별 이전에 붙인다면?
	// const StatInfo* info
	// info가 가리키고 있는 바구니의 내용물을 바꿀 수 없음
	// 원격 바구니의 내용물을 바꿀 수 없음
	// info->hp = 100; <- error
	// 둘 다도 가능
}

int main()
{
	int number = 1;

	cout << number << endl;
	int* pointer = &number;
	*pointer = 2;

	cout << number << endl;
	int& reference = number;
	reference = 3;
	// pointer로 가져다쓰거나 참조로 가져다쓰거나 같은 내용이다.
	// 참조로 쓰는 경우에 포인터로 -> 접근이 아닌 .으로 사용 하지만 실제로는 주소값을 통해 원본 수정
	cout << number << endl;
	//원본수정을 방지하려면 const 키워드를 통해 개선 가능
	StatInfo info;

	StatInfo * pointer = &info;
	StatInfo& reference = info;

	//참조타입은 바구니의 별칭 같은 느낌 원본이 필요하다
	//포인터는 주소라는 의미 고로 존재하지 않을 수도 있다.

	StatInfo* statPointer = NULL;
	statPointer = nullptr;
	PrintInfo(*statPointer);
	PrintInfo(statPointer);
	//가독성 측면에서 #define OUT만을 써서 키워드만 이용하여 개선
	return 0;
}