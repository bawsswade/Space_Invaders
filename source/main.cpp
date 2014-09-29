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

//set space invaders font
const char* font = "./fonts/invaders.fnt";

//global variables
unsigned int iArcadeMarquee;

Cannon player;
Enemy Aliens[18];

//**********FUNCTIONS**************
// draw menu to screen
void UpdateMainMenu();
//player movements
void UpdateGameState();
//draw aliens to screen
void CreateEnemies();
//**********************************

int main( int argc, char* argv[] )
{	


	//initialize screen settings
	Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	//set player's cannon and movement
	player.SetPosition(iScreenWidth * .5f, iScreenHeight * .1f);
	player.SetSize(64.f, 32.f);
	player.SetMovementKeys('A', 'D');
	player.SetSpriteID(CreateSprite("./images/cannon.png", player.GetWidth(), player.GetHeight(), true));
	player.SetMoveExtremes(32.f, 575.f);
	MoveSprite(player.GetSpriteID(), player.GetX(), player.GetY());

	//set enemy display and movements
	CreateEnemies();
	int fEnemyX = iScreenWidth * .5f;
	int fEnemyY = iScreenHeight * .8f;

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
			UpdateGameState();
			break;

		case eEND:
			FrameworkUpdate() == true;
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

void UpdateGameState(){
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

	//draw aliens to screen
	for (int i = 0; i < 18; i++)
	{
		DrawSprite(Aliens[i].spriteId);
		Aliens[i].Move(fDeltaT, 1);
		if (Aliens[i].x <= Aliens[i].min + Aliens[i].width * .5f)
		{
			for (int a = 0; a < 6; a++)
			{
				Aliens[i + a].y = Aliens[i].y;
				DrawSprite(Aliens[i + a].spriteId);
				Aliens[i + a].direction = Aliens[i].direction;
			}
			i += 6;
		}
		Aliens[i].SetMoveExtremes(32.f, 625.f);
		
		if (Aliens[i].x >= Aliens[i].max )
		{
			for (int a = 0; a < 6; a++)
			{ 
				Aliens[i - a].y = Aliens[i].y;
				DrawSprite(Aliens[i - a].spriteId);
				Aliens[i - a].direction = Aliens[i].direction;
			}
			i += 6;
		}
	}
}
void CreateEnemies(){
	float enemyX = iScreenWidth * .2f;
	float enemyY = iScreenHeight * .7f;

	for (int i = 0; i < 18; ++i)
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