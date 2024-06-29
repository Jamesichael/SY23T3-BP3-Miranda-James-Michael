#pragma once
#include "GameObject.h"
#include "enemy.h"

class powerUps :public GameObject
{
public:

	powerUps(float positionX, float positionY, float height, float width, float speed);

	void start();
	void update();
	void draw();

	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();

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

