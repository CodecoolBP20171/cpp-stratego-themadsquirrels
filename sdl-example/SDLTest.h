//
// Created by lmolnar on 10/25/17.
//

#ifndef SDLTEST_SDLTEST_H
#define SDLTEST_SDLTEST_H
#include <SDL.h>
#include <string>
#include "Texture.h"

class SDLTest
{
public:
    SDLTest() : window(nullptr), renderer(nullptr) {}
    ~SDLTest();

    bool init();
    Texture loadTexture(const std::string& filename);
    // just to check SDL's bitmap loader
    Texture loadBMP(const std::string& filename);
    void getWindowSize(int& width, int& height);
    SDL_Renderer* getRenderer(){return renderer;}

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool createWindow();
    bool createRenderer();
    bool initSDLImage();
};

#endif //SDLTEST_SDLTEST_H
