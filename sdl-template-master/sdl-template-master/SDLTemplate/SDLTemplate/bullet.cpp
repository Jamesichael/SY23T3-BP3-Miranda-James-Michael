#include "bullet.h"

bullet::bullet(float positionX, float positionY, float directionX, float diractionY, float speed, Side side)
{
	this->x = positionX;
	this->y = positionY;
	this->directionX = directionX;
	this->directionY = diractionY;
	this->speed = speed;
	this->side = side;
}

void bullet::start()
{
	if(side == Side::PLAYER_SIDE)
	{
		bulletTexture = loadTexture("gfx/playerBullet.png");
	}
	else if (side == Side::ENEMY_SIDE)
	{
		bulletTexture = loadTexture("gfx/alienBullet.png");
	}

	width = 0;
	height = 0;

	SDL_QueryTexture(bulletTexture, NULL, NULL, &width, &height);
}

void bullet::update()
{
	x += directionX * speed;
	y += directionY * speed;

}

void bullet::draw()
{
	blit(bulletTexture, x, y);
}

int bullet::getPositionX()
{
	return x;
}

int bullet::getPositionY()
{
	return y;
}

int bullet::getWidth()
{
	return width;
}

int bullet::getHeight()
{
	return height;
}

Side bullet::getSide()
{
	return side;
}
