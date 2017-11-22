//
// Created by meszi on 2017.11.21..
//

#include "Game.h"

namespace stratego {

    Game::Game() {
        loadResources();
        // TODO: init fields
        // create menu (buttons)
        // create board
        // create players (piece containers, pieces)
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
                    while (gameState == GameState::SWITCHING) {
                        waitForInput();
                        // handleTurnClick() ??? taken from flowchart
                        if (gameState == GameState::PLAYER_TURN) {
                            // TODO: Execute the created player move
                            // should this than be a field of game?
                            checkForWin();
                            // TODO: Flip pieces
                        }
                    }
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
        while (gameState) {
            waitForInput();
            handleTurnClick();
            switch (gameState) {
                case GameState::SWITCHING: {
                    // TODO: create PlayerMove object
                    return;
                }
                case GameState::RESET:
                case GameState::EXIT: {
                    return;
                }
            }
        }
    }

    void Game::reset() {
        // TODO: Move pieces from board to containers
        gameState = GameState::PLAYER_SETUP;
        currentPlayer = player1;
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
