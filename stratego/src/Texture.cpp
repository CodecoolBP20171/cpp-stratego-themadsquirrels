//
// Created by lmolnar on 10/25/17.
//

#include <Texture.h>

namespace stratego {
    Texture::Texture(SDL_Texture* texture)
            : texture(texture) {
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    }

    Texture::~Texture() {
        if (texture) SDL_DestroyTexture(texture);
    }

    void Texture::render(SDL_Renderer* renderer, const SDL_Rect* pos) {
        SDL_RenderCopy(renderer, texture, nullptr, pos);
    }

    SDL_Rect Texture::getDimensions() {
        return {0, 0, width, height};
    }
}
