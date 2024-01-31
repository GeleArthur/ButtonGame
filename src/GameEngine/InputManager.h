#pragma once

class InputManager
{
public:
    static void PollEvents();
    static bool IsQuitting();

private:
    static bool m_IsQuitting;
};
