#include <renderable/clickable/displayMatrix/Board.h>
#include <Resources.h>

namespace stratego {

    Board::Board()
            : DisplayMatrix(Resources::getInstance()->getBoardBackground(),
                            10, 10,
                            ClickActionType::BOARD) {
        pieces.reserve(100);
        for (int i = 0; i < 100; ++i) pieces.emplace_back(new Piece(PieceType::EMPTY));
        pieces[gridCoordToLinear({2, 5})] = sptr<Piece>(new Piece(PieceType::WATER));
        pieces[gridCoordToLinear({2, 6})] = sptr<Piece>(new Piece(PieceType::WATER));
        pieces[gridCoordToLinear({3, 5})] = sptr<Piece>(new Piece(PieceType::WATER));
        pieces[gridCoordToLinear({3, 6})] = sptr<Piece>(new Piece(PieceType::WATER));

        pieces[gridCoordToLinear({6, 5})] = sptr<Piece>(new Piece(PieceType::WATER));
        pieces[gridCoordToLinear({6, 6})] = sptr<Piece>(new Piece(PieceType::WATER));
        pieces[gridCoordToLinear({7, 5})] = sptr<Piece>(new Piece(PieceType::WATER));
        pieces[gridCoordToLinear({7, 6})] = sptr<Piece>(new Piece(PieceType::WATER));
    }

    bool Board::isValidMove(sptr<Selection>& s1, sptr<Selection>& s2) {
        // TODO: refactor this
        auto s1pos = s1->getCoord();
        auto s2pos = s2->getCoord();
        if (s1pos.x == s2pos.x) {
            if (abs(s1pos.y - s2pos.y) == 1) return true;
            if (s1->getPieceType() == PieceType::SCOUT) {
                auto from = std::min(s1pos.y, s2pos.y);
                auto to = std::max(s1pos.y, s2pos.y);
                for (int i = from + 1; i < to; ++i) {
                    if (pieces[gridCoordToLinear({s1pos.x, i})]->getType() != PieceType::EMPTY) {
                        return false;
                    }
                }
                return true;
            }
        } else if (s1pos.y == s2pos.y) {
            if (abs(s1pos.x - s2pos.x) == 1) return true;
            if (s1->getPieceType() == PieceType::SCOUT) {
                auto from = std::min(s1pos.x, s2pos.x);
                auto to = std::max(s1pos.x, s2pos.x);
                for (int i = from + 1; i < to; ++i) {
                    if (pieces[gridCoordToLinear({i, s1pos.y})]->getType() != PieceType::EMPTY) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }

    void Board::resetPieces() {
        for (int i = 0; i < pieces.size(); ++i) {
            auto type = pieces[i]->getType();
            if (type != PieceType::EMPTY && type != PieceType::WATER) {
                pieces[i]->gotoPlayer(pieces[i]);
                pieces[i] = new Piece(PieceType::EMPTY);
            }
        }
    }
}