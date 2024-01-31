#include "GameEngine.h"

#include <chrono>

#include "Renderer.h"

#include <iostream>
#include <SDL.h>
#include <SDL_error.h>
#include <string>

#include "InputManager.h"


GameEngine::GameEngine(const int width, const int height):
    m_WindowWidth(width), m_WindowHeight(height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) Error(SDL_GetError());

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    m_Window = SDL_CreateWindow(
        "",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_WindowWidth,
        m_WindowHeight,
        SDL_WINDOW_OPENGL);

    m_Context = SDL_GL_CreateContext(m_Window);
    Renderer::Init(m_WindowWidth, m_WindowHeight);
}

GameEngine::~GameEngine()
{
    SDL_DestroyWindow(m_Window);
    SDL_GL_DeleteContext(m_Context);
}

void GameEngine::Run()
{
    const std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point prevTime = std::chrono::steady_clock::now();
    
    while (!InputManager::IsQuitting())
    {
        InputManager::PollEvents();
        if(InputManager::IsQuitting()) continue;

        std::chrono::steady_clock::time_point timeNow = std::chrono::steady_clock::now();
        currentTime = std::chrono::duration<float>(timeNow - startTime).count();
        deltaTime = std::chrono::duration<float>(timeNow - prevTime).count();
        prevTime = timeNow;


        Update();
        Render();
        SDL_GL_SwapWindow(m_Window);
    }
    Quit();
}

void GameEngine::Update()
{
    
}

void GameEngine::Render()
{
}

void GameEngine::Quit()
{
}

void GameEngine::Error(std::string message)
{
    // m_quitting = true;
    std::cout << "Error: " << message << '\n';
    throw;
    exit(-1);
}
