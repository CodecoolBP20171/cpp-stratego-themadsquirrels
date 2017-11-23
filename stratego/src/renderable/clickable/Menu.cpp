#include <renderable/clickable/Menu.h>
#include <Resources.h>

namespace stratego {

    Menu::Menu(coord pos)
            : Clickable(Resources::getInstance()->getMenuBackground(), ClickActionType::MENU) {
        setPosition(pos.x, pos.y);
        buttons.emplace_back(new Button(Resources::getInstance()->getIcon(0), ClickActionType::NEXT));
        buttons[0]->setPosition(rect.x + BUTTON_OFFSET + 0 * buttons[0]->getDimensions().x, rect.y);
        buttons.emplace_back(new Button(Resources::getInstance()->getIcon(1), ClickActionType::RESET));
        buttons[1]->setPosition(rect.x + BUTTON_OFFSET + 1 * buttons[1]->getDimensions().x, rect.y);
        buttons.emplace_back(new Button(Resources::getInstance()->getIcon(2), ClickActionType::EXIT));
        buttons[2]->setPosition(rect.x + BUTTON_OFFSET + 2 * buttons[2]->getDimensions().x, rect.y);
    }

    void Menu::render(GameState gs) {
        texture->render(&rect);
        for(auto& button : buttons){
            button->render(gs);
        }
    }

    const ClickActionType Menu::evaluateClick(const coord& mouse) const {
        ClickActionType actionType;
        for(auto& button : buttons){
            if((actionType = button->evaluateClick(mouse)) != ClickActionType::OUTSIDE){
                return actionType;
            }
        }
        return type;
    }
}