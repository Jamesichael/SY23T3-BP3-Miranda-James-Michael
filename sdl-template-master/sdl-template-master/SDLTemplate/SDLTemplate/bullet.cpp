#include "bullet.h"

bullet::bullet(float positionX, float positionY, float directionX, float diractionY, float speed)
{
	this->x = positionX;
	this->y = positionY;
	this->directionX = directionX;
	this->diractionY = diractionY;
	this->speed = speed;

}

void bullet::start()
{
	bulletTexture = loadTexture("gfx/playerBullet.png");

	width = 0;
	height = 0;

	SDL_QueryTexture(bulletTexture, NULL, NULL, &width, &height);
}

void bullet::update()
{
	x += directionX * speed;
	y += diractionY * speed;

}

void bullet::draw()
{
	blit(bulletTexture, x, y);
}

float bullet::getPositionX()
{
	return x;
}

float bullet::getPositionY()
{
	return y;
}

float bullet::getWidth()
{
	return width;
}

float bullet::getHeight()
{
	return height;
}
