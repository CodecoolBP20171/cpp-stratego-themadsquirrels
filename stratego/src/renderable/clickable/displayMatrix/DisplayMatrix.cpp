#include <renderable/clickable/displayMatrix/DisplayMatrix.h>
#include <Resources.h>

namespace stratego {

    DisplayMatrix::DisplayMatrix(sptr<Texture>& texture, int width, int height)
            : Clickable(texture, ClickActionType::MATRIX_ACTION),
              width(width),
              height(height),
              pieceSize(texture->getDimensions().w) {}

    void DisplayMatrix::movePiece(coord from, coord to) {
        int fromIdx = planarCoordToLinear(from);
        int toIdx = planarCoordToLinear(to);
        auto tmp = std::move(pieces[fromIdx]);
        pieces[fromIdx] = std::move(pieces[toIdx]);
        pieces[toIdx] = std::move(tmp);
    }

    void DisplayMatrix::addPiece(coord dest, sptr<Piece>& piece) {
        pieces[planarCoordToLinear(dest)] = piece;
    }

    sptr<Piece> DisplayMatrix::removePiece(coord from) {
        auto tmp = std::move(pieces[planarCoordToLinear(from)]);
        return tmp;
    }

    void DisplayMatrix::render(GameState gs) {
        // render background
        texture->render(&rect);
        // render contained pieces
        for (auto& piece : pieces) {
            piece->render(gs);
        }
    }

    int DisplayMatrix::planarCoordToLinear(coord pos) {
        return pos.y * width + pos.x;
    }
}