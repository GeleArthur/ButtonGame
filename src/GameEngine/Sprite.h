#pragma once
#include <SDL_opengl.h>
#include <string>
#include "../Utils/Vector2d.h"
#include "../Utils/Matrix.h"

class Sprite
{
public:
    Sprite(const char *texturePath);
    ~Sprite();
    void Draw();

    Vector2d position{};
    float rotation{0};
    Vector2d scale{1,1};

private:
    float width;
    float height;
    GLuint textureID{};
};