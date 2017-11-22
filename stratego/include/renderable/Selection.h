#ifndef STRATEGO_SELECTION_H
#define STRATEGO_SELECTION_H

#include <renderable/Renderable.h>
#include <renderable/Piece.h>
#include <strategoTypes.h>
#include <renderable/clickable/displayMatrix/DisplayMatrix.h>

namespace stratego {
    class Selection : public Renderable {
    public:
        Selection(int x, int y, sptr<DisplayMatrix>& selectedMatrix, sptr<Piece>& selectedPiece);
        void render(GameState gs) override;
        coord getCoord() const;
        PieceType getPieceType() const;
    private:
        int x, y;
        sptr<DisplayMatrix> selectedMatrix;
        sptr<Piece> selectedPiece;
    };
}

#endif //STRATEGO_SELECTION_H
