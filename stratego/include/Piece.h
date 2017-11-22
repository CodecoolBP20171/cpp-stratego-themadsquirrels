#ifndef STRATEGO_PIECE_H
#define STRATEGO_PIECE_H

#include <Renderable.h>
#include <strategoTypes.h>
#include "PieceType.h"
#include "GameState.h"
#include <Player.h>

namespace stratego {
    class Piece : public Renderable {
    public:
        explicit Piece(PieceType type, sptr<Player>& player, Resources& resources);
        PieceContainer& getPlayerContainer();
        void render(GameState gs) override;
    private:
        const PieceType type;
        const sptr<Player> player;
        // front texture stored in Renderable::texture
        const sptr<Texture> backTexture;
    };
}

#endif //STRATEGO_PIECE_H
