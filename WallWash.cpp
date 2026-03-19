#include "WallWash.h"

void WallWash::Init()
{
    cleanImg = LoadGraph("Resource/wall_clean.png");
    dirtyImg = LoadGraph("Resource/wall_dirty.png");

    GetGraphSize(cleanImg, &width, &height);

    maskImg = MakeScreen(width, height, TRUE);
    CreateMaskScreen();
    SetMaskScreenGraph(maskImg);

    // êiçsìxèâä˙âª
    cleanPower = 0;
    maxPower = width * height;
}

void WallWash::Update()
{

    int mx, my;
    GetMousePoint(&mx, &my);
    SetDrawScreen(maskImg);
    SetDrawBlendMode(DX_BLENDMODE_SRCCOLOR, 255);
    if (GetMouseInput() & MOUSE_INPUT_LEFT)
    {

        for (int i = 0; i < 30; i++)
        {
            int rx = mx + rand() % 40 - 20;
            int ry = my + rand() % 40 - 20;

            DrawCircle(rx, ry, 10, GetColor(0, 0, 0), TRUE);

            // çÌÇ¡ÇΩó Çâ¡éZ
            cleanPower += 20;
        }
    }

    SetDrawScreen(DX_SCREEN_BACK);
    // è„å¿êßå¿
    if (cleanPower > maxPower) cleanPower = maxPower;
}

void WallWash::Draw()
{
    DrawGraph(0, 0, cleanImg, TRUE);
    SetUseMaskScreenFlag(TRUE);

    DrawGraph(0, 0, dirtyImg, TRUE);
    SetUseMaskScreenFlag(FALSE);
}

float WallWash::GetCleanPercent()
{
    return (float)cleanPower / maxPower * 100.0f;
}