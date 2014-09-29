#include "Enemy.h"
//#include "SpaceInvaders.h"
#include "AIE.h"

void Enemy::SetMoveExtremes(unsigned int a_min, unsigned int a_max){
	min = a_min;
	max = a_max;
}
void Enemy::SetPosition(float a_x, float a_y){
	x = a_x;
	y = a_y;
}
bool Enemy::Move(float a_fDeltaTime, float a_Direction){
	switch (direction)
	{
	case eLeft:
		x -= a_fDeltaTime * speed;
		if (x < min){
			x = min;
			direction = eDown;
		}
		MoveSprite(spriteId, x, y);
		return true;
	case eRight:
		x += a_fDeltaTime * speed;
		if (x > max){
			x = max;
			direction = eDown;
		}
		MoveSprite(spriteId, x, y);
		return true;
	case eDown:
		if (x <= min + width * .5f){
			y -= iScreenHeight * .03f;
			MoveSprite(spriteId, x, y);
			//speed += 0;
			//tracker == true;
			direction = eRight;
		}
		else if (x >= max + width * .5f){
			y -= iScreenHeight * .03f;
			MoveSprite(spriteId, x, y);
			//speed += 0;
			//tracker == true;
			direction = eLeft;
		}
		return true;
	default:
		break;
	}
}
