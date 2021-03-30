#include <iostream>
#include <time.h>
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

	//struct StatInfo
	//{
	//	int hp;
	//	int attack;
	//	int defence;
	//};
	//StatInfo globalInfo;
	//
	//void PrintInfo(StatInfo& info)
	//{
	//	cout << "hp : " << info.hp << endl;
	//	cout << "attack : " << info.attack << endl;
	//	cout << "defence : " << info.defence << endl;
	//	//info.hp = 100; <- error
	//}
	//
	//void PrintInfo(StatInfo* info)
	//{
	//	if (info == nullptr)
	//		return; // NULL 체크
	//
	//	cout << "hp : " << info->hp << endl;
	//	cout << "attack : " << info->attack << endl;
	//	cout << "defence : " << info->defence << endl;
	//
	//	//별 뒤에 붙인다면
	//	// StatInfo * const info
	//	// info라는 바구니의 내용물(주소)를 바꿀 수 없음
	//	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다.
	//	// info = &globalInfo; <- error
	//
	//	//별 이전에 붙인다면?
	//	// const StatInfo* info
	//	// info가 가리키고 있는 바구니의 내용물을 바꿀 수 없음
	//	// 원격 바구니의 내용물을 바꿀 수 없음
	//	// info->hp = 100; <- error
	//	// 둘 다도 가능
	//}
	//
	//int main()
	//{
	//	int number = 1;
	//
	//	cout << number << endl;
	//	int* pointer = &number;
	//	*pointer = 2;
	//
	//	cout << number << endl;
	//	int& reference = number;
	//	reference = 3;
	//	// pointer로 가져다쓰거나 참조로 가져다쓰거나 같은 내용이다.
	//	// 참조로 쓰는 경우에 포인터로 -> 접근이 아닌 .으로 사용 하지만 실제로는 주소값을 통해 원본 수정
	//	cout << number << endl;
	//	//원본수정을 방지하려면 const 키워드를 통해 개선 가능
	//	StatInfo info;
	//
	//	StatInfo * pointer = &info;
	//	StatInfo& reference = info;
	//
	//	//참조타입은 바구니의 별칭 같은 느낌 원본이 필요하다
	//	//포인터는 주소라는 의미 고로 존재하지 않을 수도 있다.
	//
	//	StatInfo* statPointer = NULL;
	//	statPointer = nullptr;
	//	PrintInfo(*statPointer);
	//	PrintInfo(statPointer);
	//	//가독성 측면에서 #define OUT만을 써서 키워드만 이용하여 개선
	//	return 0;
	//}
#pragma endregion

//#pragma region Array
//
//struct StatInfo
//{
//	int hp = 0xAAAAAAAA;
//	int attack = 0xBBBBBBBB;
//	int defence = 0xDDDDDDDD;
//};
//
////배열은 넘기면 컴파일러가 포인터로 치환
////배열 내용 전체를 넘긴 것이 아닌 시작 주소를 넘긴다.
//void Test(char a[])
//{
//	a[0] = 'x';
//}
//
//int main()
//{
//	//배열의 크기는 상수여야함 VC 컴파일러 기준
//	const int monsterCount = 10;
//	StatInfo monsters[monsterCount];
//
//	StatInfo players[10];
//
//	//players = monsters;
//	//auto C++ 11에 등장 
//	//배열의 이름은 곧 배열의 시작주소
//	//시작위치를 가리키는 TYPE* 포인터
//	auto WhoAmI = monsters;
//
//	StatInfo* monster_0 = monsters;
//	monster_0->hp = 100;
//	monster_0->attack = 10;
//	monster_0->defence = 1;
//
//	StatInfo* monsters_1 = monsters + 1;//monsters[1];
//	monsters_1->hp = 200;
//	monsters_1->attack = 20;
//	monsters_1->defence = 2;
//
//	//monsters[2]의 참조 원본을 수정할 수 있다.
//	StatInfo& monster_2 = *(monsters + 2);
//
//	//monsters[2]의 값복사가 일어난 형태로 temp가 생성
//	StatInfo temp = *(monsters + 2);
//
//
//	cout << "Hello World!" << endl;
//	char msg[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
//	Test(msg);
//	cout << msg << endl;//바뀐다 msg가 xello
//	//메모리 상에서 보면 배열과 포인터는 다르다.
//	//배열 그자체가 만들어짐
//	//포인터는 주소 따로 있고 data 담긴 곳이 따로 있다.
//	return 0;
//}
//#pragma endregion

//#pragma region 로또 번호 생성기
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//
////Bubble Sort
//void Sort(int numbers[], int count)// or int* numbers
//{
//	for (int index = 0; index < count - 1; index++)
//	{
//		for (int j = index + 1; j < count; j++)
//		{
//			if (numbers[index] > numbers[j])
//				Swap(numbers[index], numbers[j]);
//		}
//	}
//}
//
//void ChooseLotto(int numbers[])
//{
//	srand((unsigned)time(0));
//	int arrayCount = 6;
//	
//	for (int index = 0; index < arrayCount; index++)
//	{
//		int number = 0;
//		bool isSame = false;
//
//		do 
//		{
//			number = rand() % 45 + 1;
//			for (int j = index - 1; j >= 0; j--)
//			{
//				if (number == numbers[j])
//				{
//					isSame = true;
//					break;
//				}
//				else
//				{
//					isSame = false;
//				}
//			}
//		} while (isSame);
//
//		numbers[index] = number;
//	}
//
//	Sort(numbers, arrayCount);
//}
//
//int main()
//{
//	//int a = 1;
//	//int b = 2;
//	//Swap(a, b);
//	//cout << a << ":" << b << endl;
//
//	int numbers[6] = {0,0,0,0,0,0};
//	//Sort(numbers, sizeof(numbers)/sizeof(int));
//	//cout << numbers << endl;
//	ChooseLotto(numbers);
//	for (int number = 0; number < 6; number++)
//	{
//		cout << "index[" << number << "] is " << numbers[number] << endl;
//	}
//	return 0;
//}
//#pragma endregion

//#pragma region 다중포인터
//
//void SetNumber(int* number)
//{
//	*number = 1;
//}
//
//void SetMessage(const char* a)
//{
//	a = "Bye";
//}
//
//void SetMessage(const char** a)
//{
//	*a = "Bye";
//}
//
//int main()
//{
//	int a = 0;
//	SetNumber(&a);
//
//	//msg[주소] << 8바이트
//	//read only data에 [H][e][l][l][o][\0]
//	//read only Bye주소 [B][y][e][\0]
//	const char* msg = "Hello";
//	const char msgTest[] = {'T','E','S','T', '\0'};
//	//[매개변수][Return][지역변수(msg(Hello 주소))][매개변수(a(Hello 주소))][Return][지역변수]
//	SetMessage(msg);
//
//	cout << msg << endl;
//
//	cout << msgTest << endl;
//	//분석은 오른쪽에서 왼쪽으로
//	
//	//.rdata Hello주소 [H][e][l][l][o][\0]
//	//msg[ Hello주소 ] << 8바이트
//	//pp[ &msg ] << 8바이트
//	const char** pp = &msg;
//	//*pp = "Bye";
//	
//	//매개변수 리턴 지역변수(msg(Hello주소)) 매개변수(a(msg의 주소))
//	SetMessage(&msg);
//	cout << msg << endl;
//	return 0;
//}
//
//#pragma endregion

//#pragma region 다차원배열 ~ 포인터 마무리
//int main()
//{
//	int apartment2D[2][5] = { {4,2,3,4,1},{1,1,5,2,2} };
//
//	//2차배열 활용예시 로그라이크 2D 맵
//	int arr2[2][2] = { {1,2},{3,4} };
//	
//	//주소2 << 4바이트
//	//주소1[주소2] X 주소1[0001]
//	//pp[주소1]
//	int (*pp)[2] = arr2;//2차원 배열과 다중포인터는 호환되지 않음
//
//	//cout << (**pp) << endl;
//	return 0;
//}
//#pragma endregion

//#pragma region 문자열 연습문제
//#pragma warning(disable:4996)//strcpy
//int main()
//{
//	const int BUF_SIZE = 100;
//
//	char a[BUF_SIZE] = "Hello";//[H][e][l][l][o][\0]
//	char b[BUF_SIZE];
//	int aLength = strlen(a);
//	cout << "aLength : " << aLength << endl;
//	strcpy(b, a);
//	cout << "strcpy Test : " << a << " result : " << b << endl;
//	return 0;
//}
//
//
//char* StrCpy(char* dest, char* src)
//{
//	//int i = 0;
//	//while (src[i] != '\0')// src[i]로 써도 null인지 아닌지 판단 가능
//	//{
//	//	dest[i] = src[i];
//	//	i++;
//	//}
//
//	//dest[i] = '\0';
//
//	char* ret = dest;
//
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;//주소값 이동
//		src++;//주소값 이동
//	}
//
//	*dest = '\0';
//
//	return ret;
//}
//
////문자열 덧붙이는 함수
//char* StrCat(char* dest, char* src)
//{
//	while (*dest != '\0')
//		dest++;
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//		//*dest++ = *src++; 위에 코드랑 같으 의미
//	}
//}
//#pragma endregion

#pragma region 파일 분할 관리
void Test_1();
void Test_2();

int main()
{

	return 0;
}


#pragma endregion