#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"

class bullet : public GameObject
{
public:
	
	bullet(float positionX, float positionY, float directionX ,float diractionY, float speed);
	
	void start();
	void update();
	void draw();

	float getPositionX();
	float getPositionY();
	float getWidth();
	float getHeight();

private:

	SDL_Texture* bulletTexture;

	int x;
	int y;
	int width;
	int height;
	int speed;
	float directionX;
	float diractionY;

};

