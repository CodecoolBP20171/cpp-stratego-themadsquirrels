#include <renderable/Player.h>
#include <Resources.h>
#include <caca_conio.h>
#include <iostream>

namespace stratego {

    Player::Player(const std::string& name, PlayerColor pc)
            : Renderable(Resources::getInstance()->getPlayerIcon(pc)),
              name(name),
              pc(pc),
              unusedPieces(new PieceContainer()),
              active(false) {}

    sptr<PieceContainer>& Player::getPieceContainer() {
        return unusedPieces;
    }

    PlayerColor Player::getPlayerColor() const {
        return pc;
    }

    void Player::activate() {
        active = true;
        unusedPieces->activate();
    }

    void Player::deactivate() {
        active = false;
        unusedPieces->deactivate();
    }

    void Player::render(GameState gs) {
        if(active){
            texture->render(&rect);
            unusedPieces->render(gs);
        }
    }

    void Player::initContainer(sptr<Player>& player) {
        unusedPieces->initPieces(player);
    }
}