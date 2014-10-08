#include "Enemy.h"
//#include "SpaceInvaders.h"
#include "AIE.h"

#include <iostream>
using namespace std;

Enemy::Enemy()
{
}

void Enemy::SetMoveExtremes(unsigned int a_min, unsigned int a_max){
	min = a_min;
	max = a_max;
}
void Enemy::SetPosition(float a_x, float a_y){
	x = a_x;
	y = a_y;
}
void Enemy::Move(float a_speed, float a_Direction, float a_fDeltaTime){
	if (isActive){
		x += a_speed * a_Direction * a_fDeltaTime;
		MoveSprite(spriteId, x, y);
	}
}
void Enemy::Draw()
{
	if (isActive)
		DrawSprite(spriteId);
}

Enemy::~Enemy()
{

}