#include <renderable/Piece.h>
#include <Resources.h>
#include <renderable/Player.h>

namespace stratego {
    Piece::Piece(PieceType type, sptr<Player>& player)
            : Renderable(Resources::getInstance()->getFrontFace(player->getPlayerColor(),type)),
              type(type),
              player(player),
              faceUp(true),
              backTexture(Resources::getInstance()->getBackFace(player->getPlayerColor())) {}

    void Piece::render(GameState gs) {
        if(faceUp) texture->render(&rect);
        else backTexture->render(&rect);
    }

    sptr<Player> Piece::getPlayer() {
        auto pl = player.lock();
        if(pl) return pl;
        else throw std::bad_weak_ptr();
    }

    const PieceType Piece::getType() const {
        return type;
    }
}
