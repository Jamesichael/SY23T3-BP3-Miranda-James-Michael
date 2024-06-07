#include "enemy.h"
#include "scene.h"
#include "util.h"
#include <vector>

enemy::~enemy()
{
	for (int i = 0; i < enemyBullets.size(); i++)
	{
		delete enemyBullets[i];
	}
	enemyBullets.clear();
}

void enemy::start()
{
	playerTexture = loadTexture("gfx/enemy.png");

	direction_X = -1;
	direction_Y = 1;
	width = 0;
	height = 0;
	speed = 2;
	reloadTime = 60;
	currentReloadTime = 0;

	directionChangeTime = (rand() % 100) + 100;
	currentDiractionChangeTime = 0;

	SDL_QueryTexture(playerTexture, NULL, NULL, &width, &height);

	s0und = SoundManager::loadSound("sound/334227__jradcoolness__laser.ogg");
}

void enemy::update()
{
	x += direction_X * speed;
	y += direction_Y * speed;
	
	if (currentDiractionChangeTime > 0)
	{
		currentDiractionChangeTime--;
	}

	if (currentDiractionChangeTime == 0) 
	{	
		direction_Y = -direction_Y;
		currentDiractionChangeTime = directionChangeTime;
	}

	if (currentReloadTime > 0)
	{
		currentReloadTime--;
	}

	if (currentReloadTime == 0)
	{
		float dX = -1;
		float dY = 0;

		calcSlope(playerTarget->getPositionX(), playerTarget->getPositionY(), x, y, &dX, &dY);

		SoundManager::playSound(s0und);
		bullet* enemyBullet = new bullet(x - width / 5, y - 1 + height / 2, dX, dY, 10, Side::ENEMY_SIDE);
		getScene()->addGameObject(enemyBullet);
		enemyBullets.push_back(enemyBullet);
		currentReloadTime = reloadTime;
	}

	for (int i = 0; i < enemyBullets.size(); i++)
	{
		if (enemyBullets[i]->getPositionX() > SCREEN_WIDTH)
		{
			bullet* bulletToErase = enemyBullets[i];
			enemyBullets.erase(enemyBullets.begin() + i);
			delete bulletToErase;

			break;
		}
	}
}

void enemy::draw()
{
	blit(playerTexture, x, y);
}

int enemy::getPositionX()
{
	return x;
}

int enemy::getPositionY()
{
	return y;
}

int enemy::getWidth()
{
	return width;
}

int enemy::getHeight()
{
	return height;
}

void enemy::setPlayerTarget(player* Player)
{
	playerTarget = Player;
}

void enemy::setPosition(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
}
