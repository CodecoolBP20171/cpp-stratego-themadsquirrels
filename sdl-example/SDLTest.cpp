#include "SDLTest.h"
#include <iostream>
#include <SDL_image.h>

SDLTest::~SDLTest()
{
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

bool SDLTest::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if(!createWindow()) return false;
    if(!createRenderer()) return false;
    if(!initSDLImage()) return false;
    return true;
}

Texture SDLTest::loadTexture(const std::string& filename)
{
    SDL_Texture* imgTexture = IMG_LoadTexture_RW(renderer,
                                                 SDL_RWFromFile(filename.c_str(), "rb"),
                                                 1);
    if(nullptr == imgTexture){
        printf( "File not found: %s SDL_image Error: %s\n", filename.c_str(), IMG_GetError() );
    }

    return Texture(imgTexture);
}

// you won't need this load function because SDL_Image is much more advanced
Texture SDLTest::loadBMP(const std::string& filename)
{
    // first load an SDL_Surface
    SDL_Surface *bmp = SDL_LoadBMP(filename.c_str());
    if (bmp == nullptr){
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    // and convert it to SDL_Texture because it's a hardware accelerated type and SDL_Surface is not
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr){
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    }

    return Texture(tex);
}

void SDLTest::getWindowSize(int& width, int& height)
{
    SDL_GetWindowSize(window, &width, &height);
}

bool SDLTest::createWindow()
{
    // check out the meaning of the parameters!
    window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

bool SDLTest::createRenderer()
{
    if(!window) return false;
    // when you have the window you need a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

bool SDLTest::initSDLImage()
{
    // SDL_Image also needs some initialization, don't forget about it
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }
    return true;
}
