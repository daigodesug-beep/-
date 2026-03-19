#include "DxLib.h"

class WallWash
{
public:
    void Init();
    void Update();
    void Draw();

    float GetCleanPercent();

private:
    int cleanImg;
    int dirtyImg;
    int maskImg;

    int width, height;

    // š’Ç‰Á
    int cleanPower;   // í‚Á‚½—Ê
    int maxPower;     // Å‘å’l
};