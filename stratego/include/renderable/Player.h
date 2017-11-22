#ifndef STRATEGO_PLAYER_H
#define STRATEGO_PLAYER_H

#include <renderable/Renderable.h>
#include <strategoTypes.h>
#include <renderable/clickable/displayMatrix/PieceContainer.h>
#include <PlayerColor.h>

namespace stratego {
    class Player : public Renderable {
    public:
        Player(const std::string& name, PlayerColor pc);
        sptr<PieceContainer>& getPieceContainer();
        PlayerColor getPlayerColor() const;

    private:
        std::string name;
        sptr<PieceContainer> unusedPieces;
        PlayerColor pc;
    };
}

#endif //STRATEGO_PLAYER_H
