//
// Created by meszi on 2017.11.21..
//

#ifndef STRATEGO_PLAYERMOVE_H
#define STRATEGO_PLAYERMOVE_H

#include <memory>
#include "strategoTypes.h"

using sptr = std::shared_ptr;

namespace stratego {
    class PlayerMove {
    public:
        PlayerMove(PlayerSPtr player, SelectionSPtr first, SelectionSPtr second) :
                player(player),
                firstSelection(first),
                secondSelection(second) {}

        void execute();

    private:
        std::weak_ptr<Player> player;
        std::shared_ptr<Selection> firstSelection;
        std::shared_ptr<Selection> secondSelection;

        void drawMove();

        void looseMove();

        void marchMove();

        void winMove();
    };
}


#endif //STRATEGO_PLAYERMOVE_H
