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
        void activate();
        void deactivate();
        void render(GameState gs) override;

    private:
        std::string name;
        bool active;
        sptr<PieceContainer> unusedPieces;
        PlayerColor pc;
    };
}

#endif //STRATEGO_PLAYER_H
