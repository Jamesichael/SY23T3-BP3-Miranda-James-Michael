#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "bullet.h"
#include "util.h"
#include <vector>

using namespace std;

class player : public GameObject
{
public:
	~player();

	void start();
	void update();
	void draw();

	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();
	bool getIsAlive();

	void ifDead();

private:

	SDL_Texture* playerTexture;
	Mix_Chunk* s0und;

	int x;
	int y;
	int width;
	int height;
	int speed;
	int speedUp;

	float reloadTime;
	float currentReloadTime;

	float reloadTimeG;
	float currentReloadTimeG;

	vector<bullet*> Bullets;
	bool isAlive;
};

