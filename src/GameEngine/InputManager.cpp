#include "InputManager.h"

#include <SDL_events.h>

const uint8_t* InputManager::m_keyBoardState{};

void InputManager::Init()
{
    m_keyBoardState = SDL_GetKeyboardState(nullptr);
}

void InputManager::PollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_IsQuitting = true;
            break;
        default:
            break;
        }
    }
}

bool InputManager::IsQuitting()
{
    return m_IsQuitting;
}

void InputManager::Quit()
{
    
}

bool InputManager::m_IsQuitting = false;
