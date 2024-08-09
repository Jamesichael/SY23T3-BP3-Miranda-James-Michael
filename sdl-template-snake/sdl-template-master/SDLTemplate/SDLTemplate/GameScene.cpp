#include "GameScene.h"

GameScene::GameScene()
{
	// Register and add game objects on constructor

	setGameBackground = new backGround();
	this->addGameObject(setGameBackground);

	player = new snake(10, 10, 1);

	player->addBodyPart(100, 50);
	player->addBodyPart(60, 50);
	player->addBodyPart(30, 50);

	this->addGameObject(player);

	fruitSpawn = new fruit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addGameObject(fruitSpawn);

	score = 0;
}

GameScene::~GameScene()
{
	delete player;
}

void GameScene::start()
{
	Scene::start();
	// Initialize any scene logic here

	initFonts();
}

void GameScene::draw()
{
	Scene::draw();

	drawText(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0, 0, TEXT_CENTER, "POINTS: ", score);

}

void GameScene::update()
{
	Scene::update();

	//plyer eats fruit collisiom
	for (int i = 0; i < objects.size(); i++)
	{
		if (player != NULL)
		{
			int collision = checkCollision(fruitSpawn->getPositionX(), fruitSpawn->getPositionY(), fruitSpawn->getWidth(), fruitSpawn->getHeight(),
				player->getDirectionX(), player->getDirectionY(), player->getWidth(), player->getHeight());

			if (collision == 1)
			{
				fruitSpawn->setPosition(rand() % 840 + 1, rand() % 560 + 1, rand() % 840 + 1, rand() % 560 + 1);
				player->addBodyPart(10, 50);
				score++;
			}
		}
	}

	//int snakeBodyCollision = checkCollision(player->);

	//wall collisions
	int wallCollision = checkCollision(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT,
	player->getX(), player->getY(), player->getWidth(), player->getHeight());

	if (wallCollision == 1)
	{
		drawText(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0, 0, TEXT_CENTER, "RESTART?");
	}
}
