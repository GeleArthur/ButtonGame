#include "InputManager.h"

#include <SDL_events.h>

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

bool InputManager::m_IsQuitting = false;
