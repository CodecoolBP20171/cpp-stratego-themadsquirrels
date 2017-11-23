//
// Created by meszi on 2017.11.21..
//

#ifndef STRATEGO_GAME_H
#define STRATEGO_GAME_H

#include <vector>
#include "strategoTypes.h"
#include "GameState.h"
#include "Resources.h"
#include "PlayerMove.h"
#include <renderable/Renderable.h>
#include <renderable/Player.h>
#include <renderable/clickable/Clickable.h>
#include <renderable/Selection.h>
#include <renderable/clickable/displayMatrix/Board.h>

namespace stratego {
    class Game {
    public:
        Game();
        GameState run();

    private:
        // we want 60fps what is 1000 ms / 60 = 16.6 frame per seconds so timestep is 16
        static const Uint32 timestep = 16;

        GameState gameState;
        sptr<Player> player1;
        sptr<Player> player2;
        sptr<Player> currentPlayer;
        sptr<Board> board;
        std::vector<sptr<Renderable>> renderObjects;
        std::vector<sptr<Clickable>> clickObjects;
        sptr<Selection> selection1;
        sptr<Selection> selection2;
        coord mouse;
        PlayerMove lastAction;

        void checkForWin();
        void playerSetup();
        void playerTurn();
        void render();
        void reset();
        void handleSetupClick();
        void handleTurnClick();
        void waitForInput();
        ClickActionType determineClickType();
        void switchPlayer();
    };
}


#endif //STRATEGO_GAME_H
