#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Entity.h"

class Enemy: public Entity{
public: 
	
	void SetMoveExtremes(unsigned int a_min, unsigned int a_max);
	void SetPosition(float a_x, float a_y);
	void Move(float delta);

	void SetSize(float width, float height);
	//void SetPosition(float x, float y);
	//******************************
	void Update(float delta);
	void Draw();

	void SetSpriteID(unsigned int spriteID);
	unsigned int GetSpriteID();

	void SetWidth(float width);
	void SetHeight(float height);

	float GetWidth();
	float GetHeight();

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

	Enemy();
	~Enemy();

	enum MOVEMENT{
		eLeft,
		eRight,
		eDown
	};

	
	const int iScreenWidth = 672;
	const int iScreenHeight = 780;

	unsigned int spriteId;
	float x, y, width, height;
	float speed = 100;
	unsigned int min, max;
	int direction = 1;
	bool isActive = true;
	//MOVEMENT direction = eLeft;
};

#endif