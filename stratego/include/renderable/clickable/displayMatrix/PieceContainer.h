#ifndef STRATEGO_PIECECONTAINER_H
#define STRATEGO_PIECECONTAINER_H

#include "DisplayMatrix.h"

namespace stratego {
    class PieceContainer : public DisplayMatrix {
    public:
        PieceContainer(sptr<Texture>& texture, sptr<SDL_Renderer>& renderer, int pieceSize);
        void addPiece(sptr<Piece>& piece);
    private:
        coord findEmptyPos();
    };
}

#endif //STRATEGO_PIECECONTAINER_H
