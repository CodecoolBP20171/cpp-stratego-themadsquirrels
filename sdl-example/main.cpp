#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDLTest.h"
#include "Texture.h"

/*
 * This is just an example code to help you started. It has design issues, missing classes
 * and smart pointers so don't take it as a stable base.
 * It also has some ideas (Texture class, anyone?) and shows how to use several important
 * parts of SDL and how to load a texture with SDL_Image.
 * So, I recommend to check it out, read the SDL documentation about the used functions and
 * make your own version what fits for you!
 *
 * NOTE: IMG_LoadTexture_RW is not in the SDL_Image documentation because the docs is old but
 * you can find some info in the source code of SDL_Image. Or just use it as I do here. :)
 * */


// returns with true if we should quit. FYI: this is not a good practice :)
bool handleEvents(SDL_Rect& r)
{
    bool quit = false;
    //Event handler
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 ) // poll for events received from user or operating system
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            quit = true;
        }
        if( e.type == SDL_MOUSEBUTTONDOWN )
        {
            r.w += 20;
            r.h += 20;
        }

        if( e.type == SDL_MOUSEBUTTONUP )
        {
            r.w -= 20;
            r.h -= 20;
        }
    }
    return quit;
}

void updatePosition(const int windowWidth, const int windowHeight, SDL_Rect& r)
{
    // change the position of the rectangle what is used to draw the second texture
    r.x += 5; r.y += 5;
    if( r.x > windowWidth &&
        r.y > windowHeight)
    {
        r.x = 0;
        r.y = 0;
    }
}

int main(int, char**){
    SDLTest test;
    test.init();
    // load pictures
    Texture pic00 = test.loadBMP("../pic/test1.bmp");
    Texture pic01 = test.loadTexture("../pic/test1.png");

    // get window sizes for te loop
    int windowWidth;
    int windowHeight;
    test.getWindowSize(windowWidth, windowHeight);

    // setup a size for the second picture
    SDL_Rect r;
    r.x = 0; r.y = 0;
    r.w = 100; r.h = 100;

    // wait a little so the animation won't start before the window appears
    SDL_Delay(100);

    bool quit = false;
    Uint32 timePassed = 0;
    Uint32 timestep = 16; // we want 60fps what is 1000 ms / 60 = 16.6 frame per seconds so timestep is 16

    // main loop, drawing happens here
    while(!quit){
        timePassed = SDL_GetTicks();

        quit = handleEvents(r);

        //First clear the renderer
        SDL_RenderClear(test.getRenderer());

        pic00.render(test.getRenderer(), nullptr);
        pic01.render(test.getRenderer(), &r);

        //Update the screen
        SDL_RenderPresent(test.getRenderer());

        updatePosition(windowWidth, windowHeight, r);

        // wait until the time declared in timestep passes
        while(timePassed + timestep > SDL_GetTicks()){
            SDL_Delay(0);
        }
    }

    return 0;
}
