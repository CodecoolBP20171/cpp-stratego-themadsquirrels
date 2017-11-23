//
// Created by meszi on 2017.11.21..
//

#include <renderable/clickable/displayMatrix/Board.h>
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

    void PlayerMove::execute(sptr <Board>& board) {
        if(!firstSelection->isActive() || !secondSelection->isActive()) return;
        auto piece1(firstSelection->getPieceType());
        auto piece2(secondSelection->getPieceType());
        if ((piece1 == PieceType::SPY && piece2 == PieceType::MARSHALL) ||
            (piece1 == PieceType::MINER && piece2 == PieceType::BOMB)) {
            winMove(board);
            return;
        }
        if (piece2 == PieceType::EMPTY) {
            marchMove();
            return;
        }
        if (piece1 == piece2) {
            drawMove();
            return;
        }
        if (piece1 > piece2) {
            winMove(board);
        } else {
            looseMove(board);
        }
    }

    void PlayerMove::drawMove() {
        firstSelection->getPiece()->gotoPlayer(firstSelection->getPiece());
        secondSelection->getPiece()->gotoPlayer(secondSelection->getPiece());
        firstSelection->deactivate();
        secondSelection->deactivate();
    }

    void PlayerMove::looseMove(sptr<Board>& board) {
        firstSelection->getPiece()->gotoPlayer(firstSelection->getPiece());
        board->removePiece(board->getGridCoordFromMousePosition(firstSelection->getPosition()));
        firstSelection->deactivate();
        secondSelection->deactivate();
    }

    void PlayerMove::marchMove() {
        firstSelection->switchWith(secondSelection);
    }

    void PlayerMove::winMove(sptr <Board>& board) {
        firstSelection->getPiece()->faceDown();
        secondSelection->getPiece()->gotoPlayer(secondSelection->getPiece());
        board->removePiece(board->getGridCoordFromMousePosition(secondSelection->getPosition()));
        firstSelection->switchWith(secondSelection);
    }
}
