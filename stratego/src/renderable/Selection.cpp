#include <renderable/Selection.h>
#include <Resources.h>

namespace stratego {
    Selection::Selection()
            : Renderable(Resources::getInstance()->getSelection()) {}

    void Selection::render(GameState gs) {
        if (active) texture->render(&rect);
    }

    coord Selection::getCoord() const {
        return {x, y};
    }

    PieceType Selection::getPieceType() const {
        return selectedPiece->getType();
    }

    void Selection::activate(coord pos, sptr<DisplayMatrix>& selectedMatrix, sptr<Piece>& selectedPiece) {
        x = pos.x;
        y = pos.y;
        this->selectedMatrix = selectedMatrix;
        this->selectedPiece = selectedPiece;
        active = true;
    }

    void Selection::deactivate() {
        active = false;
    }

    bool Selection::isActive() const {
        return active;
    }
}
