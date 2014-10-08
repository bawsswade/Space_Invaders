#include "AIE.h"
#include <iostream>
#include "Cannon.h"
#include "Enemy.h"
//#include "SpaceInvaders.h"

using namespace std;

enum GAMESTATES{
	eMAIN_MENU,
	eGAMEPLAY,
	eEND
};

enum MOVEMENT{
	eLeft,
	eRight,
	eDown
};

//set width and hight of screen
const int iScreenWidth = 672;
const int iScreenHeight = 780;
const int NUM_ALIENS = 18;


//set space invaders font
const char* font = "./fonts/invaders.fnt";

//global variables
unsigned int iArcadeMarquee;
bool alienswitch = false;

Cannon player;
Enemy Aliens[NUM_ALIENS];
Bullet bullet;

//**********FUNCTIONS**************
bool CheckAllDead();
// draw menu to screen
void UpdateMainMenu();
//player movements
void UpdateGameState(int &a_changeDir);
//draw aliens to screen
void CreateEnemies();
bool CheckCollision(float x1, float y1, float x2, float y2, float distance);

//**********************************

int main( int argc, char* argv[] )
{	


	//initialize screen settings
	Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	//set player's cannon and movement
	player.SetPosition(iScreenWidth * .5f, iScreenHeight * .1f);
	player.SetSize(64.f, 32.f);
	player.SetMovementKeys(GLFW_KEY_LEFT, GLFW_KEY_RIGHT);
	player.SetSpriteID(CreateSprite("./images/cannon.png", player.GetWidth(), player.GetHeight(), true));
	player.SetMoveExtremes(32.f, 575.f);
	MoveSprite(player.GetSpriteID(), player.GetX(), player.GetY());
	

	//set enemy display and movements
	CreateEnemies();
	int fEnemyX = iScreenWidth * .5f;
	int fEnemyY = iScreenHeight * .8f;
	int changeDir = 1;

	//set marque
	iArcadeMarquee = CreateSprite("./images/Space-Invaders-Marquee.png", iScreenWidth, iScreenHeight, true);
	MoveSprite(iArcadeMarquee, iScreenWidth *.5f, iScreenHeight * .5f);

	//initialize scores
	char score1[10] = "00000";
	char score2[10] = "00000";
	char highScore[10] = "0000";
	char credits[10] = "99";

	//add font
	AddFont(font);

	GAMESTATES eCurrentState = eMAIN_MENU;
	
    //**********Game Loop********************
    do
    {
		ClearScreen();

		//set time
		float fDeltaT = GetDeltaTime();
		//set font
		SetFont(font);

		switch (eCurrentState)
		{
		case eMAIN_MENU:
			UpdateMainMenu();
			if (IsKeyDown(257))
			{
				eCurrentState = eGAMEPLAY;
			}
			break;

		case eGAMEPLAY:
			player.Move(fDeltaT, 200);
			UpdateGameState(changeDir);
			if (IsKeyDown(GLFW_KEY_ESCAPE))
				eCurrentState = eEND;
			
			if (CheckAllDead())
				eCurrentState = eEND;
			break;

		case eEND:
			return 0;
			break;

		default:
			break;
		}

    } while(FrameworkUpdate() == false);

	//**************************************

	DestroySprite(player.GetSpriteID());
	DestroySprite(iArcadeMarquee);

    Shutdown();

    return 0;
}


void UpdateMainMenu(){
	DrawSprite(iArcadeMarquee);
	DrawString("Insert Coins", iScreenWidth * 0.37f, iScreenHeight * 0.5f);
	DrawString("Credits", iScreenWidth * 0.41f, iScreenHeight * 0.4f);
}

void UpdateGameState(int &a_changeDir){
	float fDeltaT = GetDeltaTime();

	
	//draw cannon to screen
	DrawSprite(player.GetSpriteID());
	MoveSprite(player.GetSpriteID(), player.GetX(), player.GetY());

	//draw scores to screen
	DrawString("SCORE < 1 >", iScreenWidth * 0.025f, iScreenHeight - 2);
	DrawString("HIGH SCORE", iScreenWidth * 0.4f, iScreenHeight - 2);
	DrawString("SCORE < 2 >", iScreenWidth * 0.75f, iScreenHeight - 2);
	DrawString("CREDIT 00", iScreenWidth *.7f, iScreenHeight * .05f);
	DrawString("Lives", iScreenWidth *.075f, iScreenHeight * .05f);
	DrawLine(32.f, 45.f, 640.f, 45.f, SColour(0x00, 0xFC, 0x00, 0xFF));
	bullet.textureID = CreateSprite("./images/bullet.png", 4, 12, true);

	//check switch direction
	for (int i = 0; i < NUM_ALIENS; i++)
	{
		if (Aliens[i].x > iScreenWidth * .9 || Aliens[i].x < iScreenWidth * 0.1 && !alienswitch && Aliens[i].isActive){
			alienswitch = true;
			i = NUM_ALIENS;
		}
	} 

	//moving shit
	for (int i = 0; i < NUM_ALIENS; i++)
	{
		if (alienswitch)
		{
			Aliens[i].direction *= -1;
			Aliens[i].y -= 10;

		}		
		Aliens[i].Move(Aliens[i].speed, Aliens[i].direction, fDeltaT);
		Aliens[i].Draw();
	}
	alienswitch = false;
	
	//bullet shit
	player.Shoot(bullet.textureID);
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		player.bullets[i].Update(fDeltaT);
		player.bullets[i].Draw();
	}

	//collision
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (player.bullets[i].isActive)
		{
			for (int j = 0; j < NUM_ALIENS; j++)
			{
				if (CheckCollision(player.bullets[i].x, player.bullets[i].y, Aliens[j].x, Aliens[j].y, 20.0f) && Aliens[j].isActive)
				{
					Aliens[j].isActive = false;
					player.bullets[i].isActive = false;
				}
			}
		}
	}
}


void CreateEnemies(){
	float enemyX = iScreenWidth * .2f;
	float enemyY = iScreenHeight * .7f;

	for (int i = 0; i < NUM_ALIENS; ++i)
	{
		Aliens[i].SetMoveExtremes(32.f, 625.f);
		Aliens[i].SetPosition(enemyX, enemyY);
		Aliens[i].spriteId = CreateSprite("./images/invaders/invaders_1_00.png", 40, 32, true);
		MoveSprite(Aliens[i].spriteId, enemyX, enemyY);
		enemyX += .12f* iScreenWidth;
		if (enemyX > iScreenWidth * .8f){
			enemyX = iScreenWidth * .2f;
			enemyY -= iScreenHeight * .08f;
		}
	}
}

bool CheckCollision(float x1, float y1, float x2, float y2, float distance)
{
	float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (d < distance)
		return true;
	else
		return false;
}

bool CheckAllDead()
{
	bool allDead = false;
	for (int i = 0; i < NUM_ALIENS; i++)
	{
		if (!Aliens[i].isActive)
			allDead = true;
		else
		{
			return allDead = false;
		}
	}
	return allDead;
}