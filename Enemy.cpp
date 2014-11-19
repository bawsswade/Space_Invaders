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
void Enemy::Move(float delta){
	if (isActive){
		x += speed * direction * delta;
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

void Enemy::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

/*void Enemy::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}*/

void Enemy::SetSpriteID(unsigned int spriteID)
{
	this->spriteId = spriteID;
}

unsigned int Enemy::GetSpriteID()
{
	return spriteId;
}

void Enemy::SetWidth(float width)
{
	this->width = width;
}

void Enemy::SetHeight(float height)
{
	this->height = height;
}

float Enemy::GetWidth()
{
	return width;
}

float Enemy::GetHeight()
{
	return height;
}

void Enemy::SetX(float x)
{
	this->x = x;
}

void Enemy::SetY(float y)
{
	this->y = y;
}

float Enemy::GetX()
{
	return x;
}

float Enemy::GetY()
{
	return y;
}

void Enemy::Update(float delta)
{

}