#include "fruit.h"

fruit::fruit(int _x, int _y, int _width, int _height)
{
	this->x = _x;
	this->y = _y;
	this->width = _width;
	this->height = _height;
}

void fruit::start()
{
	fruitTexture = loadTexture("snake_graphics/Graphics/apple.png");
	SDL_QueryTexture(fruitTexture, NULL, NULL, &width, &height);
}

void fruit::update()
{

}

void fruit::draw()
{
	blit(fruitTexture, x, y);
}

int fruit::getPositionX()
{
	return x;
}

int fruit::getPositionY()
{
	return y;
}

int fruit::getWidth()
{
	return width;
}

int fruit::getHeight()
{
	return height;
}

void fruit::setPosition(int _x, int _y, int _width, int _height)
{
	this->x = _x;
	this->y = _y;
	this->width = _width;
	this->height = _height;
}
