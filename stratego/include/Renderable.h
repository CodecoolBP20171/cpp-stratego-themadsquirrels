#ifndef STRATEGO_RENDERABLE_H
#define STRATEGO_RENDERABLE_H

#include <strategoTypes.h>
#include "GameState.h"

namespace stratego {
    class Renderable {
    public:
        explicit Renderable(sptr<Texture>& texture, sptr<SDL_Renderer>& renderer);
        virtual void render(GameState gs) = 0;
        void setPosition(int x, int y);
    protected:
        const wptr<Texture> texture;
        const wptr<SDL_Renderer> renderer;
        SDL_Rect rect;
    };
}

#endif //STRATEGO_RENDERABLE_H
