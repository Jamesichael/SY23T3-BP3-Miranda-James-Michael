#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "gridSystem.h"
#include "util.h"
#include <vector>

using namespace std;

class Snake : public GameObject
{
public:

    void start();
    void update();
    void draw();

    coordinate snakePosition[1000];
    coordinate snakeDirection;

    void move();
    bool collisionWall();
    bool bodyCollision();
    void grow();
    void initialize();

    int getSnakeX();
    int getSnakeY();
    int getSnakeWidth();
    int getSnakeHeight();

    bool getIsAlive();
    int getSnakeLength();

private:
    SDL_Texture* texture;

    int width;
    int height;
    int speed;
    int length;

    bool isAlive;

    int gridSize;
};
