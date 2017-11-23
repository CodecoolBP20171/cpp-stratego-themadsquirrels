//
// Created by meszi on 2017.11.22..
//

#ifndef STRATEGO_RESOURCES_H
#define STRATEGO_RESOURCES_H

#include <map>
#include <vector>
#include "strategoTypes.h"
#include "renderable/PieceType.h"
#include "Texture.h"
#include "PlayerColor.h"

namespace stratego {
    class Resources {
        static sptr<Resources> instance;
    public:

        static sptr<Resources>& getInstance();
        sptr<Texture>& getFrontFace(PlayerColor pc, PieceType pt);
        sptr<Texture>& getBackFace(PlayerColor pc);
        sptr<Texture>& getBoardBackground();
        sptr<Texture>& getMenuBackground();
        /** index 0=next, 1=reset, 2=exit */
        sptr<Texture>& getIcon(size_t index);
        sptr<Texture>& getPieceContainerBackground();
        sptr<Texture>& getSelection();
        sptr<Texture>& getPlayerBackground();

        SDL_Renderer* getRenderer();
    private:

        // TODO: Add textures for new game screen and player name
        std::unique_ptr<SDL_Window, sdl_deleter> window;
        std::unique_ptr<SDL_Renderer, sdl_deleter> renderer;
        sptr<Texture> boardBackground;
        sptr<Texture> menuBackground;
        sptr<Texture> pieceContainerBackground;
        sptr<Texture> selection;
        std::map<PlayerColor, sptr<Texture>> playerIcon;
        std::map<PlayerColor, sptr<Texture>> backFaces;
        std::map<PieceType, sptr<Texture>> blueFrontFaces;
        std::map<PieceType, sptr<Texture>> redFrontFaces;
        std::vector<sptr<Texture>> icons;

        Resources();
        void loadTextures();
    };
}


#endif //STRATEGO_RESOURCES_H
