#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "snake.h"
#include "backGround.h"
#include "text.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
	void start();
	void draw();
	void update();

private:
	snake* player;
	fruit* fruitSpawn;
	backGround* setGameBackground;
	int score;
};

