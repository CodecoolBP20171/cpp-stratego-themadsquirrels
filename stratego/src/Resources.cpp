//
// Created by meszi on 2017.11.22..
//

#include "Resources.h"

namespace stratego {
    sptr<Resources> Resources::instance = nullptr;
    Resources::Resources() :
            window(SDL_CreateWindow("TheMadSquirrels : Stratego",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    960, 640, SDL_WINDOW_SHOWN)),
            renderer(SDL_CreateRenderer(window.get(), -1,
                                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
            {}

    sptr<Resources>& Resources::getInstance() {
        if (!instance) {
            instance = sptr<Resources>(new Resources());
            instance->loadTextures();
        }
        return instance;
    }

    void Resources::loadTextures() {
        boardBackground = sptr<Texture>(new Texture("assets/board.png"));
        menuBackground = sptr<Texture>(new Texture("assets/menu.png"));
        pieceContainerBackground = sptr<Texture>(new Texture("assets/piece_container.png"));
        selection = sptr<Texture>(new Texture("assets/icon_reset.png"));
        playerBackground = sptr<Texture>(new Texture("assets/player_background.png"));
        backFaces[PlayerColor::BLUE] = sptr<Texture>(new Texture("assets/piece_back_blue.png"));
        backFaces[PlayerColor::RED] = sptr<Texture>(new Texture("assets/piece_back_red.png"));
        for (int i = 0; i < 12; ++i) {
            blueFrontFaces[static_cast<PieceType>(i)] = sptr<Texture>(new Texture("piece_" + std::to_string(i) + "_blue.png"));
            redFrontFaces[static_cast<PieceType>(i)] = sptr<Texture>(new Texture("piece_" + std::to_string(i) + "_red.png"));
        }
        icons.emplace_back(new Texture("assets/icon_next.png"));
        icons.emplace_back(new Texture("assets/icon_reset.png"));
        icons.emplace_back(new Texture("assets/icon_exit.png"));
    }

    sptr<Texture>& Resources::getFrontFace(PlayerColor pc, PieceType pt) {
        if (pc == PlayerColor::BLUE) return blueFrontFaces[pt];
        else return redFrontFaces[pt];
    }

    sptr<Texture>& Resources::getBackFace(PlayerColor pc) {
        return backFaces[pc];
    }

    sptr<Texture>& Resources::getBoardBackground() {
        return boardBackground;
    }

    sptr<Texture>& Resources::getMenuBackground() {
        return menuBackground;
    }

    sptr<Texture>& Resources::getIcon(size_t index) {
        return icons[index];
    }

    sptr<Texture>& Resources::getPieceContainerBackground() {
        return pieceContainerBackground;
    }

    sptr<Texture>& Resources::getSelection() {
        return selection;
    }

    SDL_Renderer* Resources::getRenderer() {
        return renderer.get();
    }

    sptr<Texture>& Resources::getPlayerBackground() {
        return playerBackground;
    }
}

