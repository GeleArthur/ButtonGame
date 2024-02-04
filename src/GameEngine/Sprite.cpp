#include "Sprite.h"
#include <SDL_image.h>
#include <iostream>


Sprite::Sprite(const char *texturePath)
{
    SDL_Surface *pSurface = IMG_Load(texturePath);

    if (pSurface == nullptr)
    {
        std::cerr << "TextureFromFile: SDL Error when calling IMG_Load: " << SDL_GetError() << std::endl;
        return;
    }

    width = (float)pSurface->w;
    height = (float)pSurface->h;

    GLenum pixelFormat{ GL_RGB };
    switch (pSurface->format->BytesPerPixel)
    {
        case 3:
            if (pSurface->format->Rmask == 0x000000ff)
                pixelFormat = GL_RGB;
            else
                pixelFormat = GL_BGR;
            break;
        case 4:
            if (pSurface->format->Rmask == 0x000000ff)
                pixelFormat = GL_RGBA;
            else
                pixelFormat = GL_BGRA;
            break;
        default:
            std::cerr << "TextureFromSurface error: Unknow pixel format, BytesPerPixel: " << pSurface->format->BytesPerPixel << "\nUse 32 bit or 24 bit images.\n";;
            return;
    }

    glGenTextures(1, &textureID);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, pSurface->pitch / pSurface->format->BytesPerPixel);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pSurface->w, pSurface->h, 0, pixelFormat, GL_UNSIGNED_BYTE, pSurface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    SDL_FreeSurface(pSurface);
}

Sprite::~Sprite()
{
    glDeleteTextures(1, &textureID);
}

void Sprite::Draw()
{
//    glBindTexture(GL_TEXTURE_2D, textureID);
//    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

//    glPushMatrix();
//    Matrix4x4 spriteMatrix{Matrix4x4::TranslationMatrix(position) * Matrix4x4::RotationMatrixX(rotation) * Matrix4x4::ScaleMatrix(scale)};
//    GLfloat openGlMatrix[16];
//    spriteMatrix.OpenGlArray(openGlMatrix);

//    glMultMatrixf(openGlMatrix);

    glColor4f(1, 0, 0, 1);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(0, 0);
        glVertex2f(width, 0);
        glVertex2f(width, height);
        glVertex2f(0, height);
    }
    glEnd();

    // Could be preloaded
//    glEnable(GL_TEXTURE_2D);
//    {
//        glBegin(GL_QUADS);
//        {
//            glTexCoord2f(0, 1);
//            glVertex2f(0, height);
//
//            glTexCoord2f(0, 1);
//            glVertex2f(0, 0);
//
//            glTexCoord2f(1, 1);
//            glVertex2f(width, 0);
//
//            glTexCoord2f(1, 0);
//            glVertex2f(width, height);
//        }
//        glEnd();
//    }
//    glDisable(GL_TEXTURE_2D);

//    glPopMatrix();

}
