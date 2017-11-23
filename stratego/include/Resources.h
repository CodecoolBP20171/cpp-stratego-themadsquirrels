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
    public:

        static sptr<Resources>& getInstance();
        static void releaseResources();

        sptr<Texture>& getFrontFace(PlayerColor pc, PieceType pt);
        sptr<Texture>& getBackFace(PlayerColor pc);
        sptr<Texture>& getBoardBackground();
        sptr<Texture>& getMenuBackground();
        /** index 0=next, 1=reset, 2=exit */
        sptr<Texture>& getIcon(size_t index);
        sptr<Texture>& getPieceContainerBackground();
        sptr<Texture>& getSelection();
        sptr<Texture>& getPlayerIcon(PlayerColor pc);
        sptr<Texture>& getEmptyPiece();

        SDL_Renderer* getRenderer();
    private:
        static sptr<Resources> instance;

        // TODO: Add textures for new game screen
        std::unique_ptr<SDL_Window, sdl_deleter> window;
        std::unique_ptr<SDL_Renderer, sdl_deleter> renderer;
        sptr<Texture> boardBackground;
        sptr<Texture> menuBackground;
        sptr<Texture> pieceContainerBackground;
        sptr<Texture> selection;
        sptr<Texture> emptyPiece;
        std::map<PlayerColor, sptr<Texture>> playerIcon;
        std::map<PlayerColor, sptr<Texture>> backFaces;
        std::map<PieceType, sptr<Texture>> blueFrontFaces;
        std::map<PieceType, sptr<Texture>> redFrontFaces;
        std::vector<sptr<Texture>> icons;
        void release();

        Resources();
        void loadTextures();
    };
}


#endif //STRATEGO_RESOURCES_H
