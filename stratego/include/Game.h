//
// Created by meszi on 2017.11.21..
//

#ifndef STRATEGO_GAME_H
#define STRATEGO_GAME_H

#include <vector>
#include "strategoTypes.h"
#include "GameState.h"
#include <Renderable.h>
#include <Player.h>
#include <Clickable.h>
#include <Selection.h>

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

        void checkForWin();
        void loadResources();
        void playerSetup();
        void playerTurn();
        void reset();
    };
}


#endif //STRATEGO_GAME_H