#pragma once
#include "GameObject.h"
#include <vector>
#include "common.h"
#include "draw.h"
#include "util.h"
#include "Scene.h"
#include "fruit.h"

using namespace std;

struct snakeSegment
{
    int x;
    int y;
};

class snake : public GameObject
{
public:
    snake(int _dirX, int _dirY, int _speed);
    void start();
    void update();
    void draw();
    void addBodyPart(int x, int y);
    int getX();
    int getY();
    int getDirectionX();
    int getDirectionY();
    int getWidth();
    int getHeight();
    bool getIsAlive();
    
    snakeSegment part;

private:
    vector<snakeSegment> bodyPart;
    SDL_Texture *snakeBody;
    int directionX;
    int directionY;
    int width;
    int height;
    int speed;
    bool isAlive;
};
