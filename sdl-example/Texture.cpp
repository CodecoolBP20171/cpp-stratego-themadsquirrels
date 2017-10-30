//
// Created by lmolnar on 10/25/17.
//

#include "Texture.h"

Texture::Texture(SDL_Texture* texture)
{
    this->texture = texture;
}

Texture::~Texture()
{
    if(!texture) SDL_DestroyTexture(texture);
}
