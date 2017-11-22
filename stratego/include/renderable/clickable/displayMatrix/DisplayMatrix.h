#ifndef STRATEGO_DISPLAYMATRIX_H
#define STRATEGO_DISPLAYMATRIX_H

#include <vector>
#include <renderable/Piece.h>
#include "renderable/clickable/Clickable.h"

namespace stratego {
    class DisplayMatrix : public Clickable {
    public:
        DisplayMatrix(sptr<Texture>& texture, sptr<SDL_Renderer>& renderer, int width, int height, int pieceSize);
        void movePiece(coord from, coord to);
        void addPiece(coord dest, sptr<Piece>& piece);
        sptr<Piece> removePiece(coord from);
        void render(GameState gs) override;
    private:
        int width, height;
        int pieceSize;
        std::vector<sptr<Piece>> pieces;
    };
}

#endif //STRATEGO_DISPLAYMATRIX_H
