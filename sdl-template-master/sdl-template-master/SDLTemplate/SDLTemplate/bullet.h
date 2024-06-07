#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"

enum class Side
{
	PLAYER_SIDE, ENEMY_SIDE
};

class bullet : public GameObject
{
public:
	
	bullet(float positionX, float positionY, float directionX ,float diractionY, float speed, Side side);
	
	void start();
	void update();
	void draw();

	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();

	Side getSide();

private:

	SDL_Texture* bulletTexture;
	Side side;

	int x;
	int y;
	int width;
	int height;
	int speed;
	float directionX;
	float diractionY;
};

