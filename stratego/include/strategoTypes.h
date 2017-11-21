#ifndef STRATEGO_STRATEGOTYPES_H
#define STRATEGO_STRATEGOTYPES_H

#include <memory>
#include "Texture.h"

namespace stratego {
    // TODO: remove
    class Player;
    class PieceContainer;
    class Resources;
    class Selection;
    // TODO: end remove

    using TextureSPtr = std::shared_ptr<Texture>;
    using RendererSPtr = std::shared_ptr<SDL_Renderer>;
    using PlayerSPtr = std::shared_ptr<Player>;
    using SelectionSPtr = std::shared_ptr<Selection>;
}

#endif //STRATEGO_STRATEGOTYPES_H
