#include <renderable/clickable/displayMatrix/Board.h>
#include <Resources.h>

namespace stratego {

    Board::Board()
            : DisplayMatrix(Resources::getInstance()->getBoardBackground(), 10, 10) {}

    bool Board::isValidMove(sptr<const Selection>& s1, sptr<const Selection>& s2) {

        return false;
    }
}