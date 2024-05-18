#pragma once
#include "GameObject.h"
#include "common.h"
#include "app.h"

class player :
    public GameObject
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
	int speed;
	int speedUp;

	SDL_Texture* texture;
};

