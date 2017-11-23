#include <renderable/clickable/Button.h>

namespace stratego {
    Button::Button(sptr <Texture>& texture, ClickActionType type)
            : Clickable(texture, type) {}
}
