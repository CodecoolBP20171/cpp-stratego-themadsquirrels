#include <renderable/clickable/Clickable.h>

namespace stratego {

    Clickable::Clickable(sptr<Texture>& texture, ClickActionType type)
            : Renderable(texture),
              type(type) {}
}
