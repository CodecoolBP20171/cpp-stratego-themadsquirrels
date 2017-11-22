#ifndef STRATEGO_PIECECONTAINER_H
#define STRATEGO_PIECECONTAINER_H

#include "DisplayMatrix.h"

namespace stratego {
    class PieceContainer : public DisplayMatrix {
    public:
        PieceContainer(sptr<Player> player);
        void addPiece(sptr<Piece>& piece);
    private:
        int findEmptyPos();
    };
}

#endif //STRATEGO_PIECECONTAINER_H
