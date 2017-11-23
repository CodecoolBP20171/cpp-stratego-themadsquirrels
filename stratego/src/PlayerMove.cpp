//
// Created by meszi on 2017.11.21..
//

#include "PlayerMove.h"

namespace stratego {

    PlayerMove::PlayerMove(sptr<Player> player, sptr<Selection> first, sptr<Selection> second) :
            player(player),
            firstSelection(first),
            secondSelection(second) {}
}
