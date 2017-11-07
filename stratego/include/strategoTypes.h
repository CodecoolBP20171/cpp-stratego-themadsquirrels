#ifndef STRATEGO_STRATEGOTYPES_H
#define STRATEGO_STRATEGOTYPES_H

#include <memory>
#include <Texture.h>

namespace stratego {
    using TextureSPtr = std::shared_ptr<Texture>;
    using RendererSPtr = std::shared_ptr<SDL_Renderer>;
    class Player; // TODO: remove
    using PlayerSPtr = std::shared_ptr<Player>;

    enum class GameState {
        PLAYER_1_SETUP,
        PLAYER_2_SETUP,
        SWITCHING_PLAYER,
        PLAYER_1_TURN,
        PLAYER_2_TURN,
        PLAYER_1_WIN,
        PLAYER_2_WIN,
        RESET
    };

    enum class PieceType : char {
        FLAG = 'f',
        BOMB = 'b',
        SPY = 1,
        SCOUT = 2,
        MINER = 3,
        SERGEANT = 4,
        LIEUTENANT = 5,
        CAPTAIN = 6,
        MAJOR = 7,
        COLONEL = 8,
        GENERAL = 9,
        MARSHALL = 10,
        WATER = 'w'
    };
}

#endif //STRATEGO_STRATEGOTYPES_H
