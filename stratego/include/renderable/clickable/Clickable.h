#ifndef STRATEGO_CLICKABLE_H
#define STRATEGO_CLICKABLE_H

#include <renderable/clickable/ClickActionType.h>
#include "renderable/Renderable.h"

namespace stratego {
    class Clickable : public Renderable{
    public:
        Clickable(sptr<Texture>& texture, sptr<SDL_Renderer>& renderer);
        virtual void render(GameState gs) = 0;
    private:
        ClickActionType type;
    };
}


#endif //STRATEGO_CLICKABLE_H
