//
// Created by lmolnar on 10/25/17.
//

#ifndef SDLTEST_TEXTURE_H
#define SDLTEST_TEXTURE_H
#include <string>
#include <SDL_image.h>


class Texture {
public:
    Texture(SDL_Texture* texture);
    ~Texture();
    
private:
    SDL_Texture* texture;

};


#endif //SDLTEST_TEXTURE_H
