#pragma once
#include "GameObject.h"
#include <vector>

using namespace std;

class snake : public GameObject
{
public:

    void start();
    void update();
    void draw();

    void addBodyPart();

private:
    vector<snakeSegment> bodyPart;

    int directionX;
    int directionY;
    int x;
    int y;
    int speed;

};

struct snakeSegment 
{
    int x;
    int y;
};
