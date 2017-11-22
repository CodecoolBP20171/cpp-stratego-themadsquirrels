#ifndef STRATEGO_MENU_H
#define STRATEGO_MENU_H

#include <vector>
#include "Clickable.h"

namespace stratego {
    class Menu : Clickable {
    public:
        Menu(sptr<Texture>& texture, sptr<SDL_Renderer>& renderer);
        void render(GameState gs) override;
    private:
        std::vector<sptr<Texture>> buttons;
    };
}

#endif //STRATEGO_MENU_H
