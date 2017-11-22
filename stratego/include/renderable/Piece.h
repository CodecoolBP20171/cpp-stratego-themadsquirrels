#ifndef STRATEGO_PIECE_H
#define STRATEGO_PIECE_H

#include <renderable/Renderable.h>
#include <strategoTypes.h>
#include "PieceType.h"
#include "GameState.h"

namespace stratego {
    class Player;
    class Piece : public Renderable {
    public:
        explicit Piece(PieceType type, sptr<Player>& player, Resources& resources);
        sptr<Player> getPlayerContainer();
        void render(GameState gs) override;
    private:
        const PieceType type;
        const wptr<Player> player;
        // front texture stored in Renderable::texture
        const sptr<Texture> backTexture;
    };
}

#endif //STRATEGO_PIECE_H
