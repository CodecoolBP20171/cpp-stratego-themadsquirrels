#include <renderable/clickable/Clickable.h>

namespace stratego {

    Clickable::Clickable(sptr<Texture>& texture, ClickActionType type)
            : Renderable(texture),
              type(type) {}

    const ClickActionType Clickable::evaluateClick(const coord &mouse) const {
        if (!(
                mouse.x >= rect.x && mouse.x <= rect.x + rect.w &&
                mouse.y >= rect.y && mouse.y <= rect.y + rect.h
        )) {
            return ClickActionType::OUTSIDE;
        }
        return type;

    }
}
