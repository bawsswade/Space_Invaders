#include "AIE.h"
#include "Entity.h"
#ifndef _BULLET_H_
#define _BULLET_H_

class Bullet : public Entity
{
public:
	void SetSize(float width, float height);
	void SetPosition(float x, float y);

	virtual void Move(float delta);
	virtual void Draw();

	void SetSpriteID(unsigned int aspriteID);
	unsigned int GetSpriteID();

	void SetWidth(float width);
	void SetHeight(float height);

	float GetWidth();
	float GetHeight();

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

	bool GetActive();
	void SetActive(bool a_isActive);

	void InitialiseBullet(float x, float y, float velocityX, float velocityY, unsigned int textureID);

	Bullet();
	~Bullet();

private:
	float x;
	float y;

	float width;
	float height;

	unsigned int spriteId;

	float velocityX;
	float velocityY;

	//void Update(float delta);
	//void Draw();

	bool isActive;
};

#endif