#include "GameScene.h"

GameScene::GameScene()
{
	// Register and add game objects on constructor
	player_1 = new player();
	this->addGameObject(player_1);
}

GameScene::~GameScene()
{
	delete player_1;
}

void GameScene::start()
{
	Scene::start();
	// Initialize any scene logic here
}

void GameScene::draw()
{
	Scene::draw();
}

void GameScene::update()
{
	Scene::update();
}
