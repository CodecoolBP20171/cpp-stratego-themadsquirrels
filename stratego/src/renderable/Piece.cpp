#include <renderable/Piece.h>
#include <Resources.h>
#include <renderable/Player.h>

namespace stratego {
    Piece::Piece(PieceType type, sptr<Player>& player)
            : Renderable(Resources::getInstance()->getFrontFace(player->getPlayerColor(),type)),
              type(type),
              player(player),
              _faceUp(true),
              backTexture(Resources::getInstance()->getBackFace(player->getPlayerColor())) {}

    Piece::Piece(PieceType type)
    : Renderable(Resources::getInstance()->getEmptyPiece()),
      type(type),
      _faceUp(true),
      backTexture(Resources::getInstance()->getEmptyPiece()){
    }

    void Piece::render(GameState gs) {
        if(_faceUp) texture->render(&rect);
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

    void Piece::faceUp() {
        _faceUp = true;
    }

    void Piece::faceDown() {
        _faceUp = false;
    }
}
