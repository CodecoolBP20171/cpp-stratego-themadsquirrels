//
// Created by lmolnar on 10/25/17.
//

#ifndef STRATEGO_TEXTURE_H
#define STRATEGO_TEXTURE_H

#include <string>
#include <memory>
#include <SDL_image.h>
#include <strategoTypes.h>

namespace stratego {
    class Texture {
    public:
        explicit Texture(const std::string fileName);
        virtual ~Texture();
        void render(const SDL_Rect* pos);
        SDL_Rect getDimensions();
    private:
        SDL_Texture* texture;
        int width, height;
    };
}

#endif //STRATEGO_TEXTURE_H
