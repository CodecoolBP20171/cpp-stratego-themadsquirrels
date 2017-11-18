#ifndef STRATEGO_STRATEGOTYPES_H
#define STRATEGO_STRATEGOTYPES_H

#include <memory>
#include <Texture.h>

namespace stratego {
    // TODO: remove
    class Player;
    class PieceContainer;
    class Resources;
    // TODO: end remove

    using TextureSPtr = std::shared_ptr<Texture>;
    using RendererSPtr = std::shared_ptr<SDL_Renderer>;
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

    enum class PieceType {
        FLAG = 0,
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
        BOMB = 11,
        WATER = 50,
        EMPTY = 100
    };
}

#endif //STRATEGO_STRATEGOTYPES_H
