#ifndef STRATEGO_BOARD_H
#define STRATEGO_BOARD_H

#include "DisplayMatrix.h"
#include "renderable/Selection.h"

namespace stratego {
    class Board : public DisplayMatrix {
    public:
        Board();
        bool isValidMove(sptr<const Selection>& s1, sptr<const Selection>& s2);
    };
}

#endif //STRATEGO_BOARD_H
