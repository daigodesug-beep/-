#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);

    Game game;
    game.Init();

    while (ProcessMessage() == 0)
    {
        game.Update();
        game.Draw();
    }

    DxLib_End();
    return 0;
}