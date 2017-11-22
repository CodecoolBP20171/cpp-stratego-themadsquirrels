#include <renderable/clickable/displayMatrix/PieceContainer.h>
#include <Resources.h>

namespace stratego {

    PieceContainer::PieceContainer()
            : DisplayMatrix(Resources::getInstance()->getPieceContainerBackground(), 5, 8)
              {}

    void PieceContainer::addPiece(sptr<Piece>& piece) {
        pieces[findEmptyPos()] = piece;
    }

    int PieceContainer::findEmptyPos() {
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                int idx = planarCoordToLinear({col, row});
                if (!pieces[idx]) {
                    return idx;
                }
            }
        }
        throw std::length_error("panic");
    }
}