#include "snake.h"
#include "Scene.h"
#include "util.h"

void Snake::start()
{
	texture = loadTexture("snake_graphics/body_vertical.png");

	width = 1;
	height = 1;
	length = 5;
	speed = 1;
	snakeDirection.x = 3;
	snakeDirection.y = 0;
	gridSize = 3;

	isAlive = true;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Snake::update()
{
	if (app.keyboard[SDL_SCANCODE_W])
	{
		if (snakeDirection.y == 0)
		{
			snakeDirection.x = 0;
			snakeDirection.y = -(gridSize);
		}
	}

	if (app.keyboard[SDL_SCANCODE_S])
	{
		if (snakeDirection.y == 0)
		{
			snakeDirection.x = 0;
			snakeDirection.y = gridSize;
		}
	}
	if (app.keyboard[SDL_SCANCODE_A])
	{
		if (snakeDirection.x == 0)
		{
			snakeDirection.x = -(gridSize);
			snakeDirection.y = 0;
		}
	}
	if (app.keyboard[SDL_SCANCODE_D])
	{
		if (snakeDirection.x == 0)
		{
			snakeDirection.x = gridSize;
			snakeDirection.y = 0;
		}
	}
}

void Snake::draw()
{
	if (!isAlive) 
		return;
		move();

	if (collisionWall()) 
	{
		isAlive = false;
	}
	if (bodyCollision())
	{
		isAlive = false;
	}

	for (int i = 0; i < length; i++)
	{
		blit(texture, snakePosition[i].x, snakePosition[i].y);
	}
}


void Snake::move()
{
	for (int i = length - 1; i > 0; i--)
	{
		snakePosition[i].x = snakePosition[i - 1].x;
		snakePosition[i].y = snakePosition[i - 1].y;
	}
	snakePosition[0].x = snakePosition[0].x + snakeDirection.x;
	snakePosition[0].y = snakePosition[0].y + snakeDirection.y;
}

bool Snake::collisionWall()
{
	if (snakePosition[0].x < 0) 
		return true;
	if (snakePosition[0].x > SCREEN_WIDTH) 
		return true;
	if (snakePosition[0].y < 0) 
		return true;
	if (snakePosition[0].y > SCREEN_HEIGHT) 
		return true;
	return false;
}

bool Snake::bodyCollision()
{

	for (int i = 5; i < length; i++)
	{
		int collision = checkCollision(snakePosition[0].x, snakePosition[0].y, 5, 5,
			snakePosition[i].x, snakePosition[i].y, 5, 5);

		if (collision == 1)
		{
			return true;
		}
	}
	return false;
}


void Snake::grow()
{
	snakePosition[length].x = snakePosition[length - 1].x;
	snakePosition[length].y = snakePosition[length - 1].y;
}

void Snake::initialize()
{
	snakePosition[0].x = 200;
	snakePosition[0].y = 200;
}

int Snake::getSnakeX()
{
	return snakePosition[0].x;
}

int Snake::getSnakeY()
{
	return snakePosition[0].y;
}

int Snake::getSnakeWidth()
{
	return width;
}

int Snake::getSnakeHeight()
{
	return height;
}
bool Snake::getIsAlive()
{
	return isAlive;
}

int Snake::getSnakeLength()
{
	return length;
}