#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "bullet.h"
#include "util.h"
#include <vector>
#include "player.h"
#include "powerUps.h"
#include "scene.h"

using namespace std;

class enemy : public GameObject
{
public:
	~enemy();

	void start();
	void update();
	void draw();
	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();
	void setPosition(int _x, int _y);
	void setPlayerTarget(player* target);
	bool getEnemyIsAlive();
	void ifDead();

private:

	SDL_Texture* enemyTexture;
	Mix_Chunk* s0und;
	SDL_Texture* deathExplosion;
	player* playerTarget;
	int x;
	int y;
	float direction_X;
	float direction_Y;
	int width;
	int height;
	int speed;
	float reloadTime;
	float currentReloadTime;
	float directionChangeTime;
	float currentDiractionChangeTime;
	vector<bullet*> enemyBullets;
	bool enemyIsAlive;
};

