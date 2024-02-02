#pragma once
#include <cstdint>

class InputManager
{
public:
    static void Init();
    static void PollEvents();
    static bool IsQuitting();
    static void Quit();

private:
    static bool m_IsQuitting;
    static const uint8_t* m_keyBoardState;
};
