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
	spriteId = a_spriteID;
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

void Cannon :: Move(float delta){

	if (IsKeyDown(iMoveLeftKey)){
		x -= delta * speed;
		if (x < (min + width * .5f))
			x = min + width * .5f;
	}
	if (IsKeyDown(iMoveRightKey)){
		x += delta * speed;
		if (x >(max + width * .5f))
			x = max + width * .5f;
	}
	MoveSprite(spriteId, x, y);
}

Cannon::~Cannon()
{

}

Bullet& Cannon::GetInactiveBullet()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!bullets[i].GetActive())
		{
			return bullets[i];
		}
	}

	return this->bullets[0];
}

void Cannon::Shoot(unsigned int textureID)
{

	if (IsKeyDown(GLFW_KEY_SPACE) && currentReloadBulletTime > maxBulletReloadTime)
	{
			GetInactiveBullet().InitialiseBullet(x, y, 0, 400, textureID);
			currentReloadBulletTime = .0f;

	}
	currentReloadBulletTime += GetDeltaTime();
}


int Cannon::GetSpeed()
{
	return speed;
}

void Cannon::Draw()
{
	MoveSprite(spriteId, x, y);
	DrawSprite(spriteId);
}