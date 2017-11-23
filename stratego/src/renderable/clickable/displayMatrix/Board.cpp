#include <renderable/clickable/displayMatrix/Board.h>
#include <Resources.h>

namespace stratego {

    Board::Board()
            : DisplayMatrix(Resources::getInstance()->getBoardBackground(), 10, 10) {
        pieces.reserve(100);
        sptr<Player> noplayer = nullptr;
        for (int i = 0; i < 100; ++i) pieces.emplace_back(new Piece(PieceType::EMPTY, noplayer));
        pieces[planarCoordToLinear({2, 5})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));
        pieces[planarCoordToLinear({2, 6})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));
        pieces[planarCoordToLinear({3, 5})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));
        pieces[planarCoordToLinear({3, 6})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));

        pieces[planarCoordToLinear({6, 5})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));
        pieces[planarCoordToLinear({6, 6})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));
        pieces[planarCoordToLinear({7, 5})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));
        pieces[planarCoordToLinear({7, 6})] = sptr<Piece>(new Piece(PieceType::WATER, noplayer));
    }

    bool Board::isValidMove(sptr<const Selection> &s1, sptr<const Selection> &s2) {
        // TODO: refactor this
        auto s1pos = s1->getCoord();
        auto s2pos = s2->getCoord();
        if (s1pos.x == s2pos.x) {
            if (abs(s1pos.y - s2pos.y) == 1) return true;
            if (s1->getPieceType() == PieceType::SCOUT) {
                auto from = std::min(s1pos.y, s2pos.y);
                auto to = std::max(s1pos.y, s2pos.y);
                for (int i = from + 1; i < to; ++i) {
                    if (pieces[planarCoordToLinear({s1pos.x, i})]->getType() != PieceType::EMPTY) {
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
                    if (pieces[planarCoordToLinear({i, s1pos.y})]->getType() != PieceType::EMPTY) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
}