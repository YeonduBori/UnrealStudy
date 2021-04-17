#include <iostream>
using namespace std;
#include "Player.h"
//전방선언

int main()
{
	Player p1; // 지역변수(스택)
	Player* p2 = new Player();// Heap
	return 0;
}
