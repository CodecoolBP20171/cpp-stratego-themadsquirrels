#ifndef STRATEGO_MENU_H
#define STRATEGO_MENU_H

#include <vector>
#include <renderable/clickable/Button.h>
#include "Clickable.h"

namespace stratego {
    class Menu : Clickable {
    public:
        Menu(coord pos);
        void render(GameState gs) override;
    private:
        const ClickActionType evaluateClick(const coord& mouse) const override;
    private:
        const int BUTTON_OFFSET = 128;
        std::vector<sptr<Button>> buttons;
    };
}

#endif //STRATEGO_MENU_H
