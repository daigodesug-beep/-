#include "WallWash.h"

void WallWash::Init()
{
    cleanImg = LoadGraph("Resource/wall_clean.png");
    dirtyImg = LoadGraph("Resource/wall_dirty.png");

    GetGraphSize(cleanImg, &width, &height);

    maskImg = MakeScreen(width, height, TRUE);

    SetDrawScreen(maskImg);
    DrawBox(0, 0, width, height, GetColor(255, 255, 255), TRUE);
    SetDrawScreen(DX_SCREEN_BACK);

    // ★進行度初期化
    cleanPower = 0;
    maxPower = width * height;
}

void WallWash::Update()
{
    int mx, my;
    GetMousePoint(&mx, &my);

    if (GetMouseInput() & MOUSE_INPUT_LEFT)
    {
        SetDrawScreen(maskImg);

        for (int i = 0; i < 30; i++)
        {
            int rx = mx + rand() % 40 - 20;
            int ry = my + rand() % 40 - 20;

            DrawCircle(rx, ry, 10, GetColor(0, 0, 0), TRUE);

            // ★削った量を加算（適当でOK）
            cleanPower += 200;
        }

        SetDrawScreen(DX_SCREEN_BACK);
    }

    // 上限制限
    if (cleanPower > maxPower) cleanPower = maxPower;
}

void WallWash::Draw()
{
    DrawGraph(0, 0, cleanImg, TRUE);
    DrawGraph(0, 0, dirtyImg, FALSE);

    SetDrawBlendMode(DX_BLENDMODE_MULA, 255);
    DrawGraph(0, 0, maskImg, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

float WallWash::GetCleanPercent()
{
    return (float)cleanPower / maxPower * 100.0f;
}