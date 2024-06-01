#include "enemyBullet.h"

enemyBullet::enemyBullet(float positionX, float positionY, float directionX, float diractionY, float speed)
{
	this->x = positionX;
	this->y = positionY;
	this->directionX = directionX;
	this->diractionY = diractionY;
	this->speed = speed;
}

void enemyBullet::start()
{
	bulletTexture = loadTexture("gfx/alienBullet.png");

	width = 0;
	height = 0;

	SDL_QueryTexture(bulletTexture, NULL, NULL, &width, &height);
}

void enemyBullet::update()
{
	x += directionX * speed;
	y += diractionY * speed;
}

void enemyBullet::draw()
{
	blit(bulletTexture, x, y);
}

float enemyBullet::getPositionX()
{
	return x;
}

float enemyBullet::getPositionY()
{
	return y;
}

float enemyBullet::getWidth()
{
	return width;
}

float enemyBullet::getHeight()
{
	return height;
}
