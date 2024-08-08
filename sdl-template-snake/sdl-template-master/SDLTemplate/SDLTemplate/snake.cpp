#include "snake.h"
#include "Scene.h"

snake::snake(int _x, int _y,int _dirX, int _dirY, int _speed)
{
	this->x = _x;
	this->y = _y;
	this->directionX = _dirX;
	this->directionY = _dirY;
	this->speed = _speed;
	
}

void snake::start()
{

	width = 0;
	height = 0;

	snakeBody = loadTexture("snake_graphics/Graphics/body_vertical.png");
}

void snake::update()
{
	for (int i = bodyPart.size() - 1; i > 0; i--) 
	{
		bodyPart[i].x = bodyPart[i - 1].x;
		bodyPart[i].y = bodyPart[i - 1].y;
	}

	bodyPart[0].x += directionX * speed;
	
	if (app.keyboard[SDL_SCANCODE_W])
	{
		bodyPart[0].y += -directionY * speed;
		bodyPart[0].x -= directionX * speed;
	}
	if (app.keyboard[SDL_SCANCODE_A])
	{
		bodyPart[0].x += -directionX * speed;
		bodyPart[0].x += -directionX * speed;
	}
	if (app.keyboard[SDL_SCANCODE_S])
	{
		bodyPart[0].x += -directionX * speed;
		bodyPart[0].y += directionY * speed;
	}
	if (app.keyboard[SDL_SCANCODE_D])
	{
		bodyPart[0].x += directionX * speed;
	}
}

void snake::draw()
{
	for (int i = 0; i < bodyPart.size(); i++)
	{
		blit(snakeBody, bodyPart[i].x, bodyPart[i].y);
	}
}

void snake::addBodyPart(int x, int y)
{
	snakeSegment part;
	part.x = x;
	part.y = y;
	bodyPart.push_back(part);

}

int snake::getX()
{
	return x;
}

int snake::getY()
{
	return y;
}

int snake::getDirectionX()
{
	return directionX;
}

int snake::getDirectionY()
{
	return directionY;
}

int snake::getWidth()
{
	return width;
}

int snake::getHeight()
{
	return height;
}

bool snake::getIsAlive()
{
	return isAlive;
}