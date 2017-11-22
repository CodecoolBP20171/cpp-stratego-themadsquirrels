//
// Created by meszi on 2017.11.22..
//

#ifndef STRATEGO_RESOURCES_H
#define STRATEGO_RESOURCES_H

#include <map>
#include <vector>
#include "strategoTypes.h"
#include "PieceType.h"
#include "Texture.h"
#include "PlayerColor.h"

namespace stratego {
    class Resources {
    public:
        static sptr<Resources>& getInstance();

        sptr<const Texture>& getFrontFace(PlayerColor pc, PieceType pt);
        sptr<const Texture>& getBackFace(PlayerColor pc);
        sptr<const Texture>& getBoardBackground();
        sptr<const Texture>& getMenuBackground();
        /** index 0=next, 1=reset, 2=exit */
        sptr<const Texture>& getIcon(size_t index);
        sptr<const Texture>& getPieceContainerBackground();
        sptr<const Texture>& getSelection();
        sptr<const SDL_Renderer>& getRenderer();

    private:
        static sptr<Resources> instance;

        // TODO: Add textures for new game screen and player name
        uptr<SDL_Window> window;
        sptr<SDL_Renderer> renderer;
        sptr<const Texture> boardBackground;
        sptr<const Texture> menuBackground;
        sptr<const Texture> pieceContainerBackground;
        sptr<const Texture> selection;
        std::map<PlayerColor, sptr<const Texture>> backFaces;
        std::map<PieceType, sptr<const Texture>> blueFrontFaces;
        std::map<PieceType, sptr<const Texture>> redFrontFaces;
        std::vector<sptr<const Texture>> icons;

        Resources();
    };
}


#endif //STRATEGO_RESOURCES_H
