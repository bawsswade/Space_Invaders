#pragma once
class Entity
{
public:
	Entity();

	void SetSize(float width, float height);
	void SetPosition(float x, float y);

	//virtual void Update(float delta) = 0;
	virtual void Move(float delta) = 0;
	virtual void Draw() = 0;

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

	~Entity();

protected:

	unsigned int spriteId;

	float width;
	float height;

	float x;
	float y;

};