#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "player.h"
#include "enemy.h"
#include "vector"
#include "text.h"
#include "draw.h"
#include "backGround.h"
#include "powerUps.h"
#include "enemyBoss.h"

using namespace std;

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
	backGround* setGameBackground;
	powerUps* spawnPowerUps;

	float spawnTime;
	float currentSpawnTime;
	vector<enemy*> spawnedEnemies;

	void spawnCheck();
	void collisionCheck();
	void spawn();
	void despawn(enemy* _enemy);

	int score;

};

