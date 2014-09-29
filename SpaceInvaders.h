#ifndef SPACE_INVADERS
#define SPACE_INVADERS
#include "Enemy.h"
#include "Cannon.h"

enum GAMESTATES{
	eMAIN_MENU,
	eGAMEPLAY,
	eEND
};

Cannon player;
Enemy Aliens[18];

/*enum MOVEMENT{
	eLeft,
	eRight,
	eDown
};*/

//set width and hight of screen
const int iScreenWidth = 672;
const int iScreenHeight = 780;

//set space invaders font
const char* font = "./fonts/invaders.fnt";

//global variables
unsigned int iArcadeMarquee;


//**********FUNCTIONS**************
// draw menu to screen
void UpdateMainMenu();
//player movements
void UpdateGameState();
//draw aliens to screen
void CreateEnemies();
//**********************************

#endif