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
        explicit Piece(PieceType type, sptr<Player>& player);
        Piece(PieceType type);
        sptr<Player> getPlayer();
        void render(GameState gs) override;
        const PieceType getType() const;
        void faceUp();
        void faceDown();

    private:
        const PieceType type;
        const wptr<Player> player;
        bool _faceUp;
        // front texture stored in Renderable::texture
        sptr<Texture> backTexture;
    };
}

#endif //STRATEGO_PIECE_H
