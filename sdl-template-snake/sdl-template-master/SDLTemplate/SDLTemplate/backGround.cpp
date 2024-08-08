#include "backGround.h"

void backGround::start()
{
	setGameBackground = loadTexture("snake_graphics/Graphics/background.png");
}

void backGround::update()
{
}

void backGround::draw()
{
	blit(setGameBackground, 0, 0);
	blit(setGameBackground, 140, 0);
	blit(setGameBackground, 280, 0);
	blit(setGameBackground, 420, 0);
	blit(setGameBackground, 560, 0);
	blit(setGameBackground, 700, 0);

	blit(setGameBackground, 0, 140);
	blit(setGameBackground, 140, 140);
	blit(setGameBackground, 280, 140);
	blit(setGameBackground, 420, 140);
	blit(setGameBackground, 560, 140);
	blit(setGameBackground, 700, 140);

	blit(setGameBackground, 0, 280);
	blit(setGameBackground, 140, 280);
	blit(setGameBackground, 280, 280);
	blit(setGameBackground, 420, 280);
	blit(setGameBackground, 560, 280);
	blit(setGameBackground, 700, 280);

	blit(setGameBackground, 0, 420);
	blit(setGameBackground, 140, 420);
	blit(setGameBackground, 280, 420);
	blit(setGameBackground, 420, 420);
	blit(setGameBackground, 560, 420);
	blit(setGameBackground, 700, 420);

	blit(setGameBackground, 0, 560);
	blit(setGameBackground, 140, 560);
	blit(setGameBackground, 280, 560);
	blit(setGameBackground, 420, 560);
	blit(setGameBackground, 560, 560);
	blit(setGameBackground, 700, 560);
}

