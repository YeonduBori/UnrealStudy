#include "Player.h"
#include "Monster.h"

//포인터 타입은 전방선언해도 되지만
//포인터의 경우 다 크기가 일괄적
//하지만 실질적인 사용은 헤더파일이 필요하기 때문에
//임포트 해줘야함
void Player::KillMonster()
{
	_target2->_hp = 0;
}