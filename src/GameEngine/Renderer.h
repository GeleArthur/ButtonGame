#pragma once
#include <cstdint>

class Renderer
{
public:
    static void Init(int width, int height);

private:
    static const uint8_t* m_keyBoardState;
};
