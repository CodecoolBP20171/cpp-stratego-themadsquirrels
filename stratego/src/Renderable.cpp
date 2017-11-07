#include <Renderable.h>

namespace stratego {
    Renderable::Renderable(TextureSPtr& texture, RendererSPtr& renderer)
            : texture(texture),
              renderer(renderer),
              rect(texture->getDimensions()) {}

    void Renderable::setPosition(int x, int y) {
        rect.x = x;
        rect.y = y;
    }
}