#include "Cannon.h"

Cannon::Cannon()
{
}

void Cannon :: SetSize(float a_width, float a_height){
	width = a_width;
	height = a_height;
}
void Cannon:: SetPosition(float a_x, float a_y){
	x = a_x;
	y = a_y;
}
void Cannon :: SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight){
	iMoveLeftKey = a_moveLeft;
	iMoveRightKey = a_moveRight;
}
void Cannon :: SetMoveExtremes(unsigned int a_min, unsigned int a_max){
	min = a_min;
	max = a_max;
}

void Cannon::SetSpriteID(unsigned int a_spriteID)
{
	a_spriteID = spriteId;
}

unsigned int Cannon::GetSpriteID()
{
	return spriteId;
}

float Cannon::GetX()
{
	return x;
}

float Cannon::GetY()
{
	return y;
}

float Cannon::GetWidth()
{
	return width;
}

float Cannon::GetHeight()
{
	return height;
}

void Cannon :: Move(float a_TimeStep, float a_Speed){

	if (IsKeyDown(iMoveLeftKey)){
		x -= a_TimeStep * a_Speed;
		if (x < (min + width * .5f))
			x = min + width * .5f;
	}
	if (IsKeyDown(iMoveRightKey)){
		x += a_TimeStep * a_Speed;
		if (x >(max + width * .5f))
			x = max + width * .5f;
	}
	MoveSprite(spriteId, x, y);
}

Cannon::~Cannon()
{

}