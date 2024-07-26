#include "snake.h"

void snake::start()
{

}

void snake::update()
{
	snakeSegment head = bodyPart[0];

	snakeSegment body = bodyPart[1];
	body.x = head.x;
	body.y = head.y;


	head.x = directionX * speed;
	head.y = directionY * speed;

	bodyPart[1].x = bodyPart[2].x;
	bodyPart[1].y= bodyPart[2].y;

}

void snake::draw()
{
}

void snake::addBodyPart()
{
	snakeSegment part;
	bodyPart.push_back(part);

}
