#include <renderable/clickable/displayMatrix/PieceContainer.h>
#include <Resources.h>

namespace stratego {

    PieceContainer::PieceContainer(sptr<Player> player)
            : DisplayMatrix(Resources::getInstance()->getPieceContainerBackground(),
                            5, 8,
                            ClickActionType::CONTAINER) {
        pieces.reserve(40);
        pieces.emplace_back(new Piece(PieceType::FLAG, player));
        pieces.emplace_back(new Piece(PieceType::SPY, player));
        pieces.emplace_back(new Piece(PieceType::GENERAL, player));
        pieces.emplace_back(new Piece(PieceType::MARSHALL, player));
        pieces.emplace_back(new Piece(PieceType::COLONEL, player));
        pieces.emplace_back(new Piece(PieceType::COLONEL, player));
        for (int i = 0; i < 6; ++i) pieces.emplace_back(new Piece(PieceType::BOMB, player));
        for (int i = 0; i < 8; ++i) pieces.emplace_back(new Piece(PieceType::SCOUT, player));
        for (int i = 0; i < 5; ++i) pieces.emplace_back(new Piece(PieceType::MINER, player));
        for (int i = 0; i < 4; ++i) {
            pieces.emplace_back(new Piece(PieceType::SERGANT, player));
            pieces.emplace_back(new Piece(PieceType::LIEUTENANT, player));
            pieces.emplace_back(new Piece(PieceType::CAPTAIN, player));
        }
        for (int i = 0; i < 3; ++i) pieces.emplace_back(new Piece(PieceType::MAJOR, player));
    }

    void PieceContainer::addPiece(sptr<Piece>& piece) {
        int idx = findEmptyPos();
        auto pos = linearToGridCoord(idx);
        pieces[idx] = piece;
        pieces[idx]->setPosition(pos.x, pos.y);
    }

    int PieceContainer::findEmptyPos() {
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                int idx = gridCoordToLinear({col, row});
                if (pieces[idx]->getType() == PieceType::EMPTY) {
                    return idx;
                }
            }
        }
        throw std::length_error("panic");
    }
}