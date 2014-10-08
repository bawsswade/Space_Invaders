#include "Bullet.h"

Bullet::Bullet()
{
}

void Bullet::Draw()
{
	if (isActive)
	{
		MoveSprite(textureID, x, y);
		DrawSprite(textureID);
	}
}

void Bullet::Update(float delta)
{
	if (isActive)
	{
		x += velocityX * delta;
		y += velocityY * delta;
	}
	if (y > 1000)
	{
		isActive = false;
	}
}

void Bullet::InitialiseBullet(float x, float y, float velocityX, float velocityY, unsigned int textureID)
{
	this->x = x;
	this->y = y;
	this->velocityX = velocityX;
	this->velocityY = velocityY;
	this->textureID = textureID;

	isActive = true;
}


Bullet::~Bullet()
{
}