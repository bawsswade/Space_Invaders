#include "SpaceInvaders.h"
#include "AIE.h"

void UpdateMainMenu(){
	DrawSprite(iArcadeMarquee);
	DrawString("Insert Coins", iScreenWidth * 0.37f, iScreenHeight * 0.5f);
	DrawString("Credits", iScreenWidth * 0.41f, iScreenHeight * 0.4f);
}

void UpdateGameState(){
	float fDeltaT = GetDeltaTime();
	//draw cannon to screen
	DrawSprite(player.spriteId);
	MoveSprite(player.spriteId, player.x, player.y);

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
				//Aliens[i + a].speed += 100;
				//Aliens[i + a].Move(fDeltaT, 1);
			}
			i += 6;
			//Aliens[i].tracker == false;
		}
		Aliens[i].SetMoveExtremes(32.f, 625.f);
		//cout << Aliens[i].max;
		if (Aliens[i].x >= Aliens[i].max /*+ Aliens[i].width * .5f*/)
		{
			for (int a = 0; a < 6; a++)
			{
				Aliens[i - a].y = Aliens[i].y;
				DrawSprite(Aliens[i - a].spriteId);
				Aliens[i - a].direction = Aliens[i].direction;
				//Aliens[i + a].speed += 100;
				//Aliens[i + a].Move(fDeltaT, 1);
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