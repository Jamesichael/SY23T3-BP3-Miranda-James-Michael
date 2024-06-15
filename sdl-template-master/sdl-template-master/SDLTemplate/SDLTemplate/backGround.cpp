#include "backGround.h"

void backGround::start()
{
	setGameBackground = loadTexture("gfx/background.png");
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;


	SDL_QueryTexture(setGameBackground, NULL, NULL, &width, &height);

}

void backGround::update()
{
}

void backGround::draw()
{
	blit(setGameBackground, 0, 0);
	blit(setGameBackground, 500, 0);
	blit(setGameBackground, 0, 500);
	blit(setGameBackground, 500, 500);
}

void backGround::setSize(int w, int h)
{
	this->width = w;
	this->height = h;
}
