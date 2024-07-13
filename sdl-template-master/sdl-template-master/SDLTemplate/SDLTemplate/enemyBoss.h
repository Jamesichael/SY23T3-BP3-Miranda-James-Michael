#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "bullet.h"
#include "util.h"
#include <vector>
#include "player.h"
#include "scene.h"

class enemyBoss : public GameObject
{
public:
	~enemyBoss();

	void start();
	void update();
	void draw();

	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();

	void setPlayerTarget(player* Player);
	void setPosition(int _x, int _y);
	bool getEnemyIsAlive();
	void ifDead();

private:

	SDL_Texture* bossTexture;
	Mix_Chunk* s0und;
	SDL_Texture* deathExplosion;
	Mix_Chunk* deathSound;
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
	bool bossIsAlive;

};