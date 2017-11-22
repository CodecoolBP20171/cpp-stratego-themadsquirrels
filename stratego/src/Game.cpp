//
// Created by meszi on 2017.11.21..
//

#include "Game.h"

namespace stratego {

    Game::Game() :
            gameState(GameState::PLAYER_SETUP) {
        loadResources();
        currentPlayer = player1;
    }

    GameState Game::run() {
        reset();
        bool quit = false;
        while (!quit) {
            render();
            switch(gameState) {
                case GameState::PLAYER_TURN: {
                    playerTurn();
                    break;
                }
                case GameState::SWITCHING: {
                    break;
                }
                case GameState::PLAYER_WIN:
                case GameState::RESET:
                case GameState::EXIT: {
                    return gameState;
                }
            }
        }
    }

    void Game::checkForWin() {

    }

    void Game::loadResources() {

    }

    void Game::playerSetup() {
        while (gameState == GameState::PLAYER_SETUP) {
            waitForInput();
            handleSetupClick();
            switch (gameState) {
                case GameState::PLAYER_SETUP: {
                    if (selection2 != nullptr) {
                        // TODO: switch two selected pieces
                    }
                    render();
                    break;
                }
                case GameState::SWITCHING: {
                    // TODO: proper condition for exiting function.
                    // currentPlayer.getContainer.size() == 0
                    if (false) {
                        return;
                    }
                    break;
                }
                case GameState::EXIT: {
                    return;
                }
            }
        }
    }

    void Game::playerTurn() {

    }

    void Game::reset() {
        playerSetup();
        if (gameState == GameState::EXIT) return;
        currentPlayer = player2;
        playerSetup();
        currentPlayer = player1;
    }

    void Game::waitForInput() {
        SDL_Event e;
        bool returnToGameFlow = false;
        while (!returnToGameFlow) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    gameState = GameState::EXIT;
                    returnToGameFlow = true;
                }
                if (e.type == SDL_MOUSEBUTTONUP) {
                    SDL_GetMouseState(&mouseX, &mouseY);
                    returnToGameFlow = true;
                }
            }
        }
    }
}
