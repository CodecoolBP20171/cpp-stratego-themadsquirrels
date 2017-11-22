#include <Piece.h>

namespace stratego {
    Piece::Piece(PieceType type, sptr<Player>& player, Resources& resources)
            : Renderable(resources.getFrontTexture(type), resources.getRenderer()),
              type(type),
              player(player),
              backTexture(resources.getBackTexture()) {}

    void Piece::render(GameState gs) {
        // TODO
    }

    PieceContainer& Piece::getPlayerContainer() {
        // TODO
        return player.getPieceContainer();
    }
}
