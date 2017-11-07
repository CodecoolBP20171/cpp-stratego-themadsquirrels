#ifndef STRATEGO_PIECE_H
#define STRATEGO_PIECE_H

#include <Renderable.h>
#include <strategoTypes.h>

namespace stratego {
    class Piece : public Renderable {
    public:
        explicit Piece(PieceType type, PlayerSPtr& player, Resources& resources);
        PieceContainer& getPlayerContainer();
        void render(GameState gs) override;
    private:
        const PieceType type;
        const std::weak_ptr<Player> player;
        // front texture stored in Renderable::texture
        const std::weak_ptr<Texture> backTexture;
    };
}

#endif //STRATEGO_PIECE_H
