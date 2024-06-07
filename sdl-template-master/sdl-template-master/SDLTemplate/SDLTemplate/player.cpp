#include "player.h"
#include "Scene.h"
#include "bullet.h"

player::~player()
{
	for (int i = 0; i < Bullets.size(); i++)
	{
		delete Bullets[i];
	}
	Bullets.clear();
}

void player::start()
{
	playerTexture = loadTexture("gfx/player.png");

	x = 100;
	y = 330;
	width = 0;
	height = 0;
	speed = 2;
	speedUp = speed + 5;
	reloadTime = 10;
	currentReloadTime = 0;
	reloadTimeG = 15;
	currentReloadTimeG = 0;
	isAlive = true;

	SDL_QueryTexture(playerTexture, NULL, NULL, &width ,&height);

	s0und = SoundManager::loadSound("sound/334227__jradcoolness__laser.ogg");
}

void player::update()
{
	for (int i = 0; i < Bullets.size(); i++)
	{
		if (Bullets[i]->getPositionX() > SCREEN_WIDTH)
		{
			bullet* bulletToErase = Bullets[i];
			Bullets.erase(Bullets.begin() + i);
			delete bulletToErase;

			break;
		}
	}

	if (!isAlive)return;

	if (app.keyboard[SDL_SCANCODE_W])
	{
		y -= speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		y += speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		y += speed;
	}


	if (app.keyboard[SDL_SCANCODE_A])
	{
		x -= speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		x += speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		x += speed;
	}


	if (app.keyboard[SDL_SCANCODE_S])
	{
		y += speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		y -= speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		y -= speed;
	}


	if (app.keyboard[SDL_SCANCODE_D])
	{
		x += speed;
	}
	else if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		x -= speedUp;
	}
	else if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{
		x -= speed;
	}

	if (currentReloadTime > 0)
	{
		currentReloadTime--;
	}

	if (app.keyboard[SDL_SCANCODE_F]  && currentReloadTime == 0)
	{
		SoundManager::playSound(s0und);
		bullet* Bullet = new bullet(x + width / 2, y - 3 + height / 2, 1, 0, 10, Side::PLAYER_SIDE);
		Bullets.push_back(Bullet);
		getScene()->addGameObject(Bullet);

		currentReloadTime = reloadTime;
	}

	if (currentReloadTimeG > 0)
	{
		currentReloadTimeG--;
	}

	if (app.keyboard[SDL_SCANCODE_G] && currentReloadTimeG == 0)
	{
		SoundManager::playSound(s0und);
		bullet* twinBullet = new bullet(x + width / 6, y - 25 + height / 2, 1, 0, 10, Side::PLAYER_SIDE);
		bullet* twinBullet2 = new bullet(x + width / 6, y + 15 + height / 2, 1, 0, 10, Side::PLAYER_SIDE);

		Bullets.push_back(twinBullet);
		Bullets.push_back(twinBullet2);

		getScene()->addGameObject(twinBullet);
		getScene()->addGameObject(twinBullet2);

		currentReloadTimeG = reloadTimeG;
	}
}

void player::draw()
{
	if (!isAlive )return;

	blit(playerTexture, x, y);
}

int player::getPositionX()
{
	return x;
}

int player::getPositionY()
{
	return y;
}

int player::getWidth()
{
	return width;
}

int player::getHeight()
{
	return height;
}

bool player::getIsAlive()
{
	return isAlive;
}

void player::ifDead()
{
	isAlive = false;
}


