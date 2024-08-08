#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "util.h"

class fruit : public GameObject
{
public:
	fruit(int _x, int _y, int _width, int _height);

	void start();
	void update();
	void draw();

	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();

	void setPosition(int _x, int _y, int _width, int _height);

private:

	SDL_Texture* fruitTexture;
	int x;
	int y;
	int width;
	int height;

};

