#include <renderable/clickable/displayMatrix/DisplayMatrix.h>
#include <Resources.h>

namespace stratego {

    DisplayMatrix::DisplayMatrix(sptr <Texture>& texture, int width, int height, ClickActionType type)
            : Clickable(texture, type),
              width(width),
              height(height),
              pieceSize(texture->getDimensions().w) {}

    void DisplayMatrix::movePiece(coord from, coord to) {
        int fromIdx = gridCoordToLinear(from);
        int toIdx = gridCoordToLinear(to);
        auto tmp = std::move(pieces[fromIdx]);
        pieces[fromIdx] = std::move(pieces[toIdx]);
        pieces[toIdx] = std::move(tmp);
        pieces[toIdx]->setPosition(rect.x + to.x * pieceSize, rect.y + to.y * pieceSize);
        pieces[fromIdx]->setPosition(rect.x + from.x * pieceSize, rect.y + from.y * pieceSize);
    }

    void DisplayMatrix::addPiece(coord dest, sptr<Piece>& piece) {
        piece->setPosition(rect.x + dest.x * pieceSize, rect.y + dest.y * pieceSize);
        pieces[gridCoordToLinear(dest)] = piece;
    }

    sptr<Piece> DisplayMatrix::removePiece(coord from) {
        auto tmp = std::move(pieces[gridCoordToLinear(from)]);
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

    int DisplayMatrix::gridCoordToLinear(coord pos) {
        return pos.y * width + pos.x;
    }

    coord DisplayMatrix::getGridCoordFromMousePosition(coord mouse) const {
        mouse.x -= rect.x;
        mouse.y -= rect.y;
        return {mouse.x / pieceSize, mouse.y / pieceSize};
    }

    coord DisplayMatrix::linearToGridCoord(int idx) const {
        return {idx % width, idx / width};
    }
}