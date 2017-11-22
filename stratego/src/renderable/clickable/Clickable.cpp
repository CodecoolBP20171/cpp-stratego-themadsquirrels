#include <renderable/clickable/Clickable.h>

stratego::Clickable::Clickable(stratego::sptr<stratego::Texture>& texture, stratego::sptr<SDL_Renderer>& renderer)
        : Renderable(texture, renderer) {
}
