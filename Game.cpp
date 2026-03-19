#include "Game.h"
#include "DxLib.h"

void Game::Init()
{
    scene = TITLE;
    wall.Init();
}

void Game::Update()
{
    switch (scene)
    {
    case TITLE:
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            wall.Init();
            startTime = GetNowCount();
            scene = GAME;
        }
        break;

    case GAME:
        wall.Update();

        if (wall.GetCleanPercent() >= 95.0f)
        {
            clearTime = GetNowCount() - startTime;
            scene = CLEAR;
        }
        break;

    case CLEAR:
        if (CheckHitKey(KEY_INPUT_SPACE))
            scene = TITLE;
        break;
    }
}

void Game::Draw()
{
    ClearDrawScreen();

    switch (scene)
    {
    case TITLE:
        DrawString(300, 200, "スッキリクリーン", GetColor(255, 255, 255));
        DrawString(300, 240, "Press SPACE", GetColor(255, 255, 255));
        break;

    case GAME:
        wall.Draw();
        DrawFormatString(10, 10, GetColor(255, 255, 255),
            "Clean: %.1f%%", wall.GetCleanPercent());
        DrawFormatString(10, 30, GetColor(255, 255, 255),
            "Time: %.2f", (GetNowCount() - startTime) / 1000.0f);
        break;

    case CLEAR:
        DrawString(300, 200, "CLEAR!", GetColor(255, 255, 0));
        DrawFormatString(300, 240, GetColor(255, 255, 255),
            "Time: %.2f sec", clearTime / 1000.0f);
        break;
    }

    ScreenFlip();
}