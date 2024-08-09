#include "fruit.h"

fruit::~fruit()
{

}

void fruit::start()
{
	fruitTexture = loadTexture("snake_graphics/Graphics/apple.png");

	fruitWidth = 20;
	fruitHeight = 20;
	fruitX = 400;
	fruitY = 380;

	SDL_QueryTexture(fruitTexture, NULL, NULL, &fruitWidth, &fruitHeight);
}

void fruit::update()
{

}

void fruit::draw()
{
	blit(fruitTexture, fruitX, fruitY);
}

int fruit::getFruitX()
{
	return fruitX;
}

int fruit::getFruitY()
{
	return fruitY;
}

int fruit::getFruitWidth()
{
	return fruitWidth;
}

int fruit::getFruitHeight()
{
	return fruitHeight;
}

void fruit::newFruitPosition()
{
	fruitX = (rand() % 700);
	fruitY = (rand() % 380);
}
