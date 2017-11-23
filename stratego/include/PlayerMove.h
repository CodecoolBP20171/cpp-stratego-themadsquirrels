//
// Created by meszi on 2017.11.21..
//

#ifndef STRATEGO_PLAYERMOVE_H
#define STRATEGO_PLAYERMOVE_H

#include <memory>
#include "strategoTypes.h"
#include "renderable/Player.h"
#include "renderable/Selection.h"

namespace stratego {
    class PlayerMove {
    public:
        PlayerMove(sptr <Selection>& first, sptr <Selection>& second);
        void execute();
        const wptr<stratego::Player>& getPlayer() const;
        void setPlayer(sptr <stratego::Player>& player);
        bool isAttack() const;
    private:
        wptr<Player> player;
        sptr<Selection> firstSelection;
        sptr<Selection> secondSelection;
        void drawMove();
        void looseMove();
        void marchMove();
        void winMove();
    };
}


#endif //STRATEGO_PLAYERMOVE_H
