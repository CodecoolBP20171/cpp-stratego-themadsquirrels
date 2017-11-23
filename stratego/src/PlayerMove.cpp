//
// Created by meszi on 2017.11.21..
//

#include "PlayerMove.h"

namespace stratego {

    PlayerMove::PlayerMove(sptr<Selection>& first, sptr<Selection>& second) :
            firstSelection(first),
            secondSelection(second) {}

    const wptr<stratego::Player>& PlayerMove::getPlayer() const {
        return player;
    }

    void PlayerMove::setPlayer(sptr<stratego::Player>& player) {
        PlayerMove::player = player;
    }

    bool PlayerMove::isAttack() const {
        return !(firstSelection->getPieceType() == PieceType::EMPTY ||
                 secondSelection->getPieceType() == PieceType::EMPTY);
    }
}
