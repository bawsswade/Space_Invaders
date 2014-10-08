#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy{
public: 
	
	void SetMoveExtremes(unsigned int a_min, unsigned int a_max);
	void SetPosition(float a_x, float a_y);
	void Move(float speed, float a_Direction, float a_fDeltaTime);
	void Draw();

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