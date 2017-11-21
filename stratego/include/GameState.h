//
// Created by meszi on 2017.11.21..
//

#ifndef STRATEGO_GAMESTATE_H
#define STRATEGO_GAMESTATE_H

namespace stratego {
    enum class GameState {
        PLAYER_SETUP,
        PLAYER_TURN,
        PLAYER_WIN,
        SWITCHING,
        RESET,
        EXIT
    };
}

#endif //STRATEGO_GAMESTATE_H
