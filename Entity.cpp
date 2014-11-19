#include "Entity.h"


Entity::Entity()
{
}

void Entity::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Entity::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Entity::SetSpriteID(unsigned int spriteID)
{
	this->spriteId = spriteID;
}

unsigned int Entity::GetSpriteID()
{
	return spriteId;
}

void Entity::SetWidth(float width)
{
	this->width = width;
}

void Entity::SetHeight(float height)
{
	this->height = height;
}

float Entity::GetWidth()
{
	return width;
}

float Entity::GetHeight()
{
	return height;
}

void Entity::SetX(float x)
{
	this->x = x;
}

void Entity::SetY(float y)
{
	this->y = y;
}

float Entity::GetX()
{
	return x;
}

float Entity::GetY()
{
	return y;
}

Entity::~Entity()
{
}