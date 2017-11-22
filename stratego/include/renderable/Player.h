#ifndef STRATEGO_PLAYER_H
#define STRATEGO_PLAYER_H

#include <renderable/Renderable.h>
#include <strategoTypes.h>
#include <renderable/clickable/displayMatrix/PieceContainer.h>

namespace stratego {
    class Player : public Renderable {
    public:
        Player(const std::string& name);
        sptr<PieceContainer>& getPieceContainer();

    private:
        std::string name;
        sptr<PieceContainer> unusedPieces;
    };
}

#endif //STRATEGO_PLAYER_H