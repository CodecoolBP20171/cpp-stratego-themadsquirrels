//
// Created by meszi on 2017.11.21..
//

#ifndef STRATEGO_GAME_H
#define STRATEGO_GAME_H

#include <vector>
#include "strategoTypes.h"
#include "GameState.h"
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
        GameState gameState;
        sptr<Player> player1;
        sptr<Player> player2;
        sptr<Player> currentPlayer;
        sptr<Board> board;
        std::vector<sptr<Renderable>> renderObjects;
        std::vector<sptr<Clickable>> clickObjects;
        sptr<Selection> selection1;
        sptr<Selection> selection2;
        int mouseX;
        int mouseY;

        void checkForWin();
        void loadResources();
        void playerSetup();
        void playerTurn();
        void render();
        void reset();
        void handleSetupClick();
        void waitForInput();
    };
}


#endif //STRATEGO_GAME_H
