#ifndef STRATEGO_BUTTON_H
#define STRATEGO_BUTTON_H

#include "Clickable.h"

namespace stratego {
    class Button : public Clickable {
    public:
        Button(sptr <Texture>& texture, ClickActionType type);
        void render(GameState gs) override;
    };
}

#endif //STRATEGO_BUTTON_H
