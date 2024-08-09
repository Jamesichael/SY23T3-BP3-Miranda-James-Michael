#include "GameScene.h"

GameScene::GameScene()
{
	// Register and add game objects on constructor

	setGameBackground = new backGround();
	this->addGameObject(setGameBackground);

	player = new Snake();
	this->addGameObject(player);

	fruitSpawn = new fruit();
	this->addGameObject(fruitSpawn);
}

GameScene::~GameScene()
{
	
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

	Scene::draw();
	drawText(0, 0, 255, 255, 255, TEXT_CENTER, "POINTS: %04d", score);
	drawText(0, 10, 255, 255, 255, TEXT_CENTER, "HIGHSCORE: %04d", highScore);

	if (player->getIsAlive() == false)
	{
		drawText(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 255, 255, 255, TEXT_CENTER, "GAME OVER!");
		drawText(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 2, 255, 255, 255, TEXT_CENTER, "YOUR POINTS ARE: ");
		pointSystem();

		drawText(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 4, 255, 255, 255, TEXT_CENTER, "PRESS R TO RESTART");
		if (app.keyboard[SDL_SCANCODE_R])
		{
			player->initialize();
			GameScene::start();
		}
		score = 0;
	}

}

void GameScene::update()
{
	Scene::update();
	eatFruitCollisionCheck();
}

void GameScene::eatFruitCollisionCheck()
{
	for (int i = 0; i < objects.size(); i++)
	{

		if (player != NULL)
		{
			int collision = checkCollision(player->getSnakeX(), player->getSnakeY(), player->getSnakeWidth(),player->getSnakeHeight(),
				fruitSpawn->getFruitX(), fruitSpawn->getFruitY(), fruitSpawn->getFruitWidth(), fruitSpawn->getFruitHeight());

			if (collision == 1)
			{
				player->grow();
				fruitSpawn->newFruitPosition();
				score++;
			}
		}
	}
}
void GameScene::pointSystem()
{
	if (score > highScore)
	{
		highScore = score;
	}
}

