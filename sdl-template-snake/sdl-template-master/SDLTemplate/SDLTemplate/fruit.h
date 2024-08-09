#pragma once
#include "GameObject.h"
#include "gridSystem.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "util.h"
#include <vector>


class fruit : public GameObject
{
public:
    ~fruit();
    void start();
    void update();
    void draw();

    int getFruitX();
    int getFruitY();
    int getFruitWidth();
    int getFruitHeight();
    void newFruitPosition();

private:
    SDL_Texture* fruitTexture;

    int fruitX;
    int fruitY;
    int fruitWidth;
    int fruitHeight;
};


