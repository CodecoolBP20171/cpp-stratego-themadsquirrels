#include <renderable/Renderable.h>

namespace stratego {
    Renderable::Renderable(sptr<Texture>& texture, sptr<SDL_Renderer>& renderer)
            : texture(texture),
              renderer(renderer),
              rect(texture->getDimensions()) {}

    void Renderable::setPosition(int x, int y) {
        rect.x = x;
        rect.y = y;
    }
}
