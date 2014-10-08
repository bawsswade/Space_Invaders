#include "AIE.h"
#ifndef _BULLET_H_
#define _BULLET_H_

class Bullet
{
public:
	Bullet();
	~Bullet();

	float x;
	float y;

	float width;
	float height;

	unsigned int textureID;

	float velocityX;
	float velocityY;

	void Update(float delta);
	void Draw();
	void InitialiseBullet(float x, float y, float velocityX, float velocityY, unsigned int textureID);

	bool isActive;
};

#endif