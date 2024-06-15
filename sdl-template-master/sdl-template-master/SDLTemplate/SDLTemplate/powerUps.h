#pragma once
#include "GameObject.h"
#include "enemy.h"

class powerUps :public GameObject
{
public:
	void start();
	void update();
	void draw();

private:
	SDL_Texture* powerUpTexture;

	int x;
	int y;
	float direction_X;
	float direction_Y;

	int width;
	int height;
	int speed;
	float directionChangeTime;
	float currentDiractionChangeTime;
};

