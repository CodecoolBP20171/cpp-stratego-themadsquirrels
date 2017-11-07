#ifndef STRATEGO_RENDERABLE_H
#define STRATEGO_RENDERABLE_H

#include <strategoTypes.h>

namespace stratego {
    class Renderable {
    public:
        explicit Renderable(TextureSPtr& texture, RendererSPtr& renderer);
        virtual void render(GameState gs) = 0;
        void setPosition(int x, int y);
    protected:
        const std::weak_ptr<Texture> texture;
        const std::weak_ptr<SDL_Renderer> renderer;
        SDL_Rect rect;
    };
}

#endif //STRATEGO_RENDERABLE_H
