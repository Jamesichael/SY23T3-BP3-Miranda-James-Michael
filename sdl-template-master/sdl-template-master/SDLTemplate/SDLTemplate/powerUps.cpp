#include "powerUps.h"

powerUps::powerUps(float positionX, float positionY, float directionX, float diractionY, float speed)
{
	this->x = positionX;
	this->y = positionY;
	this->direction_X = directionX;
	this->direction_Y = diractionY;
	this->speed = speed;
}

void powerUps::start()
{

	width = 0;
	height = 0;
	speed = 2;

	directionChangeTime = (rand() % 30) + 15;
	currentDiractionChangeTime = 0;

	powerUpTexture = loadTexture("gfx/points.png");
	SDL_QueryTexture(powerUpTexture, NULL, NULL, &width, &height);

}

void powerUps::update()
{
	x += direction_X * speed;
	y += direction_Y * speed;

	if (currentDiractionChangeTime > 0)
	{
		currentDiractionChangeTime--;
	}

	if (currentDiractionChangeTime == 0)
	{
		direction_X = -direction_X;
		currentDiractionChangeTime = directionChangeTime;
	}
}

void powerUps::draw()
{
	blit(powerUpTexture, x, y);
}

int powerUps::getPositionX()
{
	return x;
}

int powerUps::getPositionY()
{
	return y;
}

int powerUps::getWidth()
{
	return width;
}

int powerUps::getHeight()
{
	return height;
}

