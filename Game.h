#pragma once
#include "WallWash.h"

enum Scene
{
    TITLE,
    GAME,
    CLEAR
};

class Game
{
public:
    void Init();
    void Update();
    void Draw();

private:
    Scene scene;
    WallWash wall;

    int startTime;
    int clearTime;
};