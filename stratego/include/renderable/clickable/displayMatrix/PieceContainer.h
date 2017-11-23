#ifndef STRATEGO_PIECECONTAINER_H
#define STRATEGO_PIECECONTAINER_H

#include "DisplayMatrix.h"

namespace stratego {
    class PieceContainer : public DisplayMatrix {
    public:
        PieceContainer();
        void initPieces(sptr<Player>& player);
        void addPiece(sptr<Piece>& piece);
        const ClickActionType evaluateClick(const coord& mouse) const override;
        void activate();
        void deactivate();
        void render(GameState gs) override;
        bool containsFlag() const;
    private:
        bool active;
        int findEmptyPos();
    };
}

#endif //STRATEGO_PIECECONTAINER_H
