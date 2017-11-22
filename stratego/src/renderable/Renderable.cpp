#include <renderable/Renderable.h>

namespace stratego {
    Renderable::Renderable(sptr<Texture>& texture)
            : texture(texture),
              rect(texture->getDimensions()) {}

    void Renderable::setPosition(int x, int y) {
        rect.x = x;
        rect.y = y;
    }
}
