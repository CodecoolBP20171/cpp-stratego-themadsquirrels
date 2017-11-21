//
// Created by meszi on 2017.11.21..
//

#ifndef STRATEGO_GAME_H
#define STRATEGO_GAME_H

#include <vector>
#include "strategoTypes.h"
#include "GameState.h"

namespace stratego {
    class Game {
    public:
        Game();

        void loadResources();
        GameState run();
        void playerTurn();
        void reset();

    private:
        GameState gameState;
        PlayerSPtr player1;
        PlayerSPtr player2;
        PlayerSPtr currentPlayer;
        std::shared_ptr<Board> board;
        std::vector<RenderableSPtr> renderObjects;
        std::vector<ClickableSPtr> clickObjects;
        SelectionSPtr selection1;
        SelectionSPtr selection2;

        void playerSetup();
        void checkForWin();
    };
}


#endif //STRATEGO_GAME_H
