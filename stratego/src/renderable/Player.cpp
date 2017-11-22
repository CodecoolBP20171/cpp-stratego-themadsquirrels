#include <renderable/Player.h>
#include <Resources.h>

namespace stratego {

    Player::Player(const std::string& name, PlayerColor pc)
            : Renderable(Resources::getInstance()->getPlayerBackground()),
              name(name),
              pc(pc),
              unusedPieces(new PieceContainer(sptr<Player>(this))) {}

    sptr<PieceContainer>& Player::getPieceContainer() {
        return unusedPieces;
    }

    PlayerColor Player::getPlayerColor() const {
        return pc;
    }
}