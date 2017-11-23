#ifndef STRATEGO_DISPLAYMATRIX_H
#define STRATEGO_DISPLAYMATRIX_H

#include <vector>
#include <renderable/Piece.h>
#include "renderable/clickable/Clickable.h"

namespace stratego {
    class DisplayMatrix : public Clickable {
    public:
        DisplayMatrix(sptr <Texture>& texture, int width, int height, ClickActionType type);
        void movePiece(coord from, coord to);
        void addPiece(coord dest, sptr<Piece>& piece);
        sptr<Piece> removePiece(coord from);
        void render(GameState gs) override;
        coord getGridCoordFromMousePosition(coord mouse) const;
        coord linearToGridCoord(int idx) const;
        void initPiecePositions();
    protected:
        int width, height;
        int pieceSize;
        std::vector<sptr<Piece>> pieces;
        int gridCoordToLinear(coord pos);
    };
}

#endif //STRATEGO_DISPLAYMATRIX_H
