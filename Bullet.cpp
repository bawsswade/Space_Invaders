#include "Bullet.h"

Bullet::Bullet()
{
}

void Bullet::Draw()
{
	if (isActive)
	{
		MoveSprite(spriteId, x, y);
		DrawSprite(spriteId);
	}
}

void Bullet::Move(float delta)
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
	this->spriteId = textureID;

	isActive = true;
}


Bullet::~Bullet()
{
}

void Bullet::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Bullet::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Bullet::SetSpriteID(unsigned int aspriteID)
{
	this->spriteId = aspriteID;
}

unsigned int Bullet::GetSpriteID()
{
	return spriteId;
}

void Bullet::SetWidth(float width)
{
	this->width = width;
}

void Bullet::SetHeight(float height)
{
	this->height = height;
}

float Bullet::GetWidth()
{
	return width;
}

float Bullet::GetHeight()
{
	return height;
}

void Bullet::SetX(float x)
{
	this->x = x;
}

void Bullet::SetY(float y)
{
	this->y = y;
}

float Bullet::GetX()
{
	return x;
}

float Bullet::GetY()
{
	return y;
}

bool Bullet::GetActive()
{
	return isActive;
}

void Bullet::SetActive(bool a_isActive)
{
	isActive = a_isActive;
}