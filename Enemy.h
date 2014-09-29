#ifndef ENEMY_H
#define ENEMY_H

class Enemy{
public: 
	void SetMoveExtremes(unsigned int a_min, unsigned int a_max);
	void SetPosition(float a_x, float a_y);
	bool Move(float a_fDeltaTime, float a_Direction);

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
	MOVEMENT direction = eLeft;
};

#endif