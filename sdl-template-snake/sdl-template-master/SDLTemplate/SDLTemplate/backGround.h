#pragma once
#include "GameObject.h"
#include "draw.h"

class backGround : public GameObject
{
public:

	void start();
	void update();
	void draw();

private:

	int x;
	int y;
	int width;
	int height;
	SDL_Texture* setGameBackground;
};

