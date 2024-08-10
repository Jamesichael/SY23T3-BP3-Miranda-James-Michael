#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "util.h"
#include "snake.h"
#include "fruit.h"
#include "backGround.h"
#include "text.h"

using namespace std;

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	void start();
	void draw();
	void update();

	void eatFruitCollisionCheck();
	void pointSystem();

private:

	Snake* player;
	fruit* fruitSpawn;
	backGround* setGameBackground;
	int score;
	int highScore;
};


