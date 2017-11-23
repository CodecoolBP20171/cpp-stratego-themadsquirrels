#include <renderable/Selection.h>
#include <Resources.h>

namespace stratego {
    Selection::Selection()
            : Renderable(Resources::getInstance()->getSelection()),
              active(false) {}

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
        setPosition(selectedPiece->getPosition());
        active = true;
    }

    void Selection::deactivate() {
        active = false;
    }

    bool Selection::isActive() const {
        return active;
    }

    void Selection::faceUp() {
        selectedPiece->faceUp();
    }

    void Selection::switchWith(sptr<Selection>& other) {
        if(selectedPiece != other->selectedPiece) {
            auto piece1 = selectedMatrix->removePiece(getCoord());
            auto piece2 = other->selectedMatrix->removePiece(other->getCoord());
            selectedMatrix->addPiece(getCoord(), piece2);
            other->selectedMatrix->addPiece(other->getCoord(), piece1);
        }
        deactivate();
        other->deactivate();
    }

    sptr<Piece>& Selection::getPiece() {
        return selectedPiece;
    }
}
