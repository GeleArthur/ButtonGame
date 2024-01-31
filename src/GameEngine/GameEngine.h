#pragma once
#include <SDL_video.h>
#include <iostream>

class GameEngine
{
public:
    GameEngine(int width, int height);
    virtual ~GameEngine();
    virtual void Run();
    
    float deltaTime{};
    float currentTime{0};


protected:
    int m_WindowWidth;
    int m_WindowHeight;
    SDL_Window* m_Window{};
    SDL_GLContext m_Context{};

    virtual void Update();
    virtual void Render();
    virtual void Quit();

    
private:
    void Error(std::string message);
};


