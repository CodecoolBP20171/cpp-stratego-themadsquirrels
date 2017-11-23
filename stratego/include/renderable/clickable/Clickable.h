#ifndef STRATEGO_CLICKABLE_H
#define STRATEGO_CLICKABLE_H

#include <renderable/clickable/ClickActionType.h>
#include "renderable/Renderable.h"

namespace stratego {
    class Clickable : public Renderable{
    public:
        Clickable(sptr<Texture>& texture, ClickActionType type);

        virtual const ClickActionType evaluateClick(const coord &mouse) const;
    protected:
        ClickActionType type;
    };
}


#endif //STRATEGO_CLICKABLE_H
