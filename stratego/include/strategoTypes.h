#ifndef STRATEGO_STRATEGOTYPES_H
#define STRATEGO_STRATEGOTYPES_H

#include <memory>
#include "Renderable.h"
#include "Texture.h"


namespace stratego {
    // TODO: remove
    class Player;
    class PieceContainer;
    class Resources;
    class Selection;
    class Board;
    class Clickable;
    // TODO: end remove

    using TextureSPtr = std::shared_ptr<Texture>;
    using RendererSPtr = std::shared_ptr<SDL_Renderer>;
    using PlayerSPtr = std::shared_ptr<Player>;
    using SelectionSPtr = std::shared_ptr<Selection>;
    using RenderableSPtr = std::shared_ptr<Renderable>;
    using ClickableSPtr = std::shared_ptr<Clickable>;
}

#endif //STRATEGO_STRATEGOTYPES_H
