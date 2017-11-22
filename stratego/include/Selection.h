#ifndef STRATEGO_SELECTION_H
#define STRATEGO_SELECTION_H

#include <Renderable.h>
#include <Piece.h>
#include <strategoTypes.h>

namespace stratego {
    class Selection : public Renderable {
    public:
        Selection();

    private:
        int x, y;
        std::shared_ptr<DisplayMatrix> selectedMatrix;
        std::shared_ptr<Piece> selectedPiece;
    };
}

#endif //STRATEGO_SELECTION_H
