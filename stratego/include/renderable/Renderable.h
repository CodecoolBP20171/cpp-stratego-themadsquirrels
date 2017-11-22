#ifndef STRATEGO_RENDERABLE_H
#define STRATEGO_RENDERABLE_H

#include "GameState.h"
#include <Texture.h>
#include <strategoTypes.h>

namespace stratego {

    class Renderable {
    public:
        explicit Renderable(sptr<Texture>& texture);
        virtual void render(GameState gs) = 0;
        void setPosition(int x, int y);
    protected:
        const sptr<Texture> texture;
        SDL_Rect rect;
    };
}

#endif //STRATEGO_RENDERABLE_H
