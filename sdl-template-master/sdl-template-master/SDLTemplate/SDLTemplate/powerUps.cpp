#include "powerUps.h"

void powerUps::start()
{
	x = 60;
	y = 200;
	
	direction_X = 1;
	direction_Y = 1;

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

