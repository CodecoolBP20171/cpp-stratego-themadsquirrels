#include <renderable/Piece.h>

namespace stratego {
    Piece::Piece(PieceType type, sptr<Player>& player, Resources& resources)
            : Renderable(resources.getFrontTexture(type), resources.getRenderer()),
              type(type),
              player(player),
              backTexture(resources.getBackTexture()) {}

    void Piece::render(GameState gs) {
        // TODO
    }

    sptr<Player> Piece::getPlayerContainer() {
        auto pl = player.lock();
        if(pl) return pl;
        else throw std::bad_weak_ptr();
    }
}