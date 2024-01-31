
#include "Renderer.h"

#ifdef W32
#include <windows.h>
#endif

#include <SDL_video.h>
#include <GL/gl.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

const uint8_t* Renderer::m_keyBoardState{};

void Renderer::Init(const int width, const int height)
{
    SDL_GL_SetSwapInterval(1);

    glViewport(0,0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, width, height, 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_keyBoardState = SDL_GetKeyboardState(nullptr);

    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

