#include <renderable/Selection.h>
#include <Resources.h>

namespace stratego {
    Selection::Selection(int x, int y, sptr<DisplayMatrix> &selectedMatrix, sptr<Piece> &selectedPiece)
            : Renderable(Resources::getInstance()->getSelection()),
              selectedMatrix(selectedMatrix),
              selectedPiece(selectedPiece),
              x(x),
              y(y) {}

    void Selection::render(GameState gs) {
        texture->render(&rect);
    }

    coord Selection::getCoord() const {
        return {x, y};
    }

    PieceType Selection::getPieceType() const {
        return selectedPiece->getType();
    }
}
