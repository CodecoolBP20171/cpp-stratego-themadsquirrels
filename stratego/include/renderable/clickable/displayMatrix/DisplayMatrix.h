#ifndef STRATEGO_DISPLAYMATRIX_H
#define STRATEGO_DISPLAYMATRIX_H

#include <vector>
#include <renderable/Piece.h>
#include "renderable/clickable/Clickable.h"

namespace stratego {
    class DisplayMatrix : public Clickable {
    public:
        DisplayMatrix(sptr<Texture>& texture, int width, int height);
        void movePiece(coord from, coord to);
        void addPiece(coord dest, sptr<Piece>& piece);
        sptr<Piece> removePiece(coord from);
        void render(GameState gs) override;
    protected:
        int width, height;
        int pieceSize;
        std::vector<sptr<Piece>> pieces;
        int planarCoordToLinear(coord pos);
    };
}

#endif //STRATEGO_DISPLAYMATRIX_H
