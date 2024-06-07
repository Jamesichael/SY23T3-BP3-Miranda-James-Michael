#include "GameScene.h"

using namespace std;

GameScene::GameScene()
{
	// Register and add game objects on constructor
	player_1 = new player();
	this->addGameObject(player_1);

	score = 0;
}

GameScene::~GameScene()
{
	delete player_1;
}

void GameScene::start()
{
	Scene::start();
	// Initialize any scene logic here

	initFonts();

	currentSpawnTime = 300;
	spawnTime = 300;

	for (int i = 0; i < 3; i++)
	{
		spawn();
	}
}

void GameScene::draw()
{
	Scene::draw();

	setGameBackground = loadTexture("gfx/background.png");

	drawText(110,20,255,255,255,TEXT_CENTER,"POINTS: %01d", score);

	if (player_1->getIsAlive() == false)
	{
		drawText(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 255, 255, 255, TEXT_CENTER, "GAME OVER!!");
	}
}

void GameScene::update()
{
	Scene::update();
	spawnCheck();
	collisionCheck();
}

void GameScene::spawnCheck()
{
	if (currentSpawnTime > 0)
	{
		currentSpawnTime--;
	}
	if (currentSpawnTime <= 0)
	{
		for (int i = 0; i < 3; i++)
		{
			spawn();
		}

		currentSpawnTime = spawnTime;
	}
}

void GameScene::collisionCheck()
{
	for (int i = 0; i < objects.size(); i++)
	{
		bullet* Bullet = dynamic_cast <bullet*>(objects[i]);
		if (Bullet != NULL)
		{
			if (Bullet->getSide() == Side::ENEMY_SIDE)
			{
				int collision = checkCollision(
					player_1->getPositionX(), player_1->getPositionY(), player_1->getWidth(), player_1->getHeight(),
					Bullet->getPositionX(), Bullet->getPositionY(), Bullet->getWidth(), Bullet->getHeight());

				if (collision == 1)
				{
					player_1->ifDead();
					break;
				}
			}
			else if (Bullet->getSide() == Side::PLAYER_SIDE)
			{
				for (int i = 0; i < spawnedEnemies.size(); i++)
				{
					enemy* currentEnemy = spawnedEnemies[i];

					int enemyCollision = checkCollision(
						currentEnemy->getPositionX(), currentEnemy->getPositionY(), currentEnemy->getWidth(),
						currentEnemy->getHeight(), Bullet->getPositionX(), Bullet->getPositionY(), Bullet->getWidth(),
						Bullet->getHeight());

					if (enemyCollision == 1)
					{
						enemyDeath = loadTexture("gfx/explosion.png");
						despawn(currentEnemy);
						score++;
						break;
					}
				}
			}
		}
	}
}

void GameScene::spawn()
{
	enemy* Enemy = new enemy();
	this->addGameObject(Enemy);
	Enemy->setPlayerTarget(player_1);

	Enemy->setPosition(1300, 300 + (rand() % 300));
	spawnedEnemies.push_back(Enemy);
}

void GameScene::despawn(enemy* _enemy)
{
	int index = -1;

	for (int i = 0; i < spawnedEnemies.size(); i++)
	{
		if(_enemy == spawnedEnemies[i])
		{ 
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		spawnedEnemies.erase(spawnedEnemies.begin() + index);
		delete _enemy;
	}
}
