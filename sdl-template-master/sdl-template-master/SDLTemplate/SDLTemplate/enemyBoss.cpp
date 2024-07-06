#include "enemyBoss.h"

enemyBoss::~enemyBoss()
{
	for (int i = 0; i < enemyBullets.size(); i++)
	{
		delete enemyBullets[i];
	}
	enemyBullets.clear();
}

void enemyBoss::start()
{
	direction_X = 1;
	direction_Y = 0;
	x = SCREEN_HEIGHT / 2;
	y = SCREEN_WIDTH / 2;
	width = 0;
	height = 0;
	speed = 2;
	reloadTime = 60;
	currentReloadTime = 0;

	directionChangeTime = (rand() % 50) + 25;
	currentDiractionChangeTime = 0;
	bossIsAlive = true;

	bossTexture = loadTexture("gfx/enemy.png");
	SDL_QueryTexture(bossTexture, NULL, NULL, &width, &height);
	s0und = SoundManager::loadSound("sound/334227__jradcoolness__laser.ogg");

}

void enemyBoss::update()
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
		bullet* enemyBullet = new bullet(x - 2 + (width / 2), y + +(height / 2), dX, dY, 10, Side::ENEMY_SIDE);
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

void enemyBoss::draw()
{
	blit(bossTexture, x, y);

	if (!bossIsAlive) return
	blit(deathExplosion, x, y);
}

int enemyBoss::getPositionX()
{
	return x;
}

int enemyBoss::getPositionY()
{
	return y;
}

int enemyBoss::getWidth()
{
	return width;
}

int enemyBoss::getHeight()
{
	return height;
}

void enemyBoss::setPlayerTarget(player* Player)
{
	playerTarget = Player;
}

void enemyBoss::setPosition(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
}

bool enemyBoss::getEnemyIsAlive()
{
	return bossIsAlive;
}

void enemyBoss::ifDead()
{
	bossIsAlive = false;
}
