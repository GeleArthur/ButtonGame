#include "ButtonGame.h"

ButtonGame::ButtonGame(): GameEngine(640, 640)
{

}

ButtonGame::~ButtonGame()
{
}

void ButtonGame::Init()
{
    //testImage = new Sprite("wood.png");
}

void ButtonGame::Update()
{
    
}

void ButtonGame::Render()
{
    glClearColor(0.3,0.1,0.1,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(0, 0, 0, 1);
    glBegin(GL_POLYGON);
    {
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 100);
        glVertex2f(0, 100);
    }
    glEnd();
}