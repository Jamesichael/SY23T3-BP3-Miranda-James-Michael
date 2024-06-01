#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "player.h"
#include "enemy.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
	void start();
	void draw();
	void update();
private:
	player* player_1;
	enemy* Enemy;

};

