//
// Created by meszi on 2017.11.22..
//

#include "Resources.h"

namespace stratego {
    Resources::Resources() :
            window(SDL_CreateWindow("TheMadSquirrels : Stratego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960,
                                    640, SDL_WINDOW_SHOWN)),
            renderer(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)),
            boardBackground(new Texture(renderer.get(), "assets/board.png")),
            menuBackground(new Texture(renderer.get(), "assets/menu.png")),
            pieceContainerBackground(new Texture(renderer.get(), "assets/piece_container.png")),
            selection(new Texture(renderer.get(), "assets/icon_reset.png")) {
        backFaces[PlayerColor::BLUE] = new Texture(renderer.get(), "assets/piece_back_blue.png");
        backFaces[PlayerColor::RED] = new Texture(renderer.get(), "assets/piece_back_red.png");
        for (int i = 0; i < 12; ++i) {
            blueFrontFaces[static_cast<PieceType>(i)] = new Texture(renderer.get(),
                                                                    "piece_" + std::to_string(i) + "_blue.png");
            redFrontFaces[static_cast<PieceType>(i)] = new Texture(renderer.get(),
                                                                   "piece_" + std::to_string(i) + "_red.png");
        }
        icons.emplace_back(new Texture(renderer.get(), "assets/icon_next.png"));
        icons.emplace_back(new Texture(renderer.get(), "assets/icon_reset.png"));
        icons.emplace_back(new Texture(renderer.get(), "assets/icon_exit.png"));
    }


    sptr<Resources> &Resources::getInstance() {
        if (!instance) instance = new Resources();
        return instance;
    }

    sptr<const Texture> &Resources::getFrontFace(PlayerColor pc, PieceType pt) {
        if (pc == PlayerColor::BLUE)    return blueFrontFaces[pt];
        else                            return redFrontFaces[pt];
    }

    sptr<const Texture> &Resources::getBackFace(PlayerColor pc) {
        return backFaces[pc];
    }

    sptr<const Texture> &Resources::getBoardBackground() {
        return boardBackground;
    }

    sptr<const Texture> &Resources::getMenuBackground() {
        return menuBackground;
    }

    sptr<const Texture> &Resources::getIcon(size_t index) {
        return icons[index];
    }

    sptr<const Texture> &Resources::getPieceContainerBackground() {
        return pieceContainerBackground;
    }

    sptr<const Texture> &Resources::getSelection() {
        return selection;
    }

    sptr<const SDL_Renderer> &Resources::getRenderer() {
        return renderer;
    }

}

