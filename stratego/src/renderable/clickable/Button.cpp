#include <renderable/clickable/Button.h>

namespace stratego {
    Button::Button(sptr <Texture>& texture, ClickActionType type)
            : Clickable(texture, type) {}

    void Button::render(GameState gs) {
        texture->render(&rect);
    }
}
