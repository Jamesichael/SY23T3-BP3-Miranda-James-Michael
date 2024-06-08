#pragma once
#include "GameObject.h"
#include "Scene.h"
#include "draw.h"

class backGround : public GameObject
{
public:

	void start();
	void update();
	void draw();

	void setSize(int w, int h);

private:

	int x;
	int y;
	int width;
	int height;

	SDL_Texture* setGameBackground;

};

