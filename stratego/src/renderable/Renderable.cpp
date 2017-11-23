#include <renderable/Renderable.h>

namespace stratego {
    Renderable::Renderable(sptr<Texture>& texture)
            : texture(texture),
              rect(texture->getDimensions()) {}

    void Renderable::setPosition(int x, int y) {
        rect.x = x;
        rect.y = y;
    }

    const coord Renderable::getDimensions() const {
        return {rect.w, rect.h};
    }

    const coord Renderable::getPosition() const {
        return {rect.x, rect.y};
    }

    void Renderable::setPosition(coord pos) {
        rect.x = pos.x;
        rect.y = pos.y;
    }
}
