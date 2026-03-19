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

    // í«â¡
    int cleanPower;   // çÌÇ¡ÇΩó 
    int maxPower;     // ç≈ëÂíl
};