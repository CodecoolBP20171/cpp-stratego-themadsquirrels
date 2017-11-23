//
// Created by meszi on 2017.11.21..
//

#include "Game.h"

namespace stratego {

    Game::Game() :
            lastAction(nullptr, nullptr, nullptr) {
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
                    // TODO: Complete flowchart implementation
                    break;
                }
                case GameState::SWITCHING: {
                    while (gameState == GameState::SWITCHING) {
                        waitForInput();
                        // handleTurnClick() ??? taken from flowchart
                        if (gameState == GameState::PLAYER_TURN) {
                            // TODO: Call execute() on the created PlayerMove object
                            // should this then be a field of game?
                            checkForWin();
                            // TODO: Flip pieces and change player
                        }
                    }
                    break;
                }
                case GameState::EXIT:
                case GameState::PLAYER_WIN:
                case GameState::RESET: {
                    return gameState;
                }
            }
        }
    }

    void Game::checkForWin() {
        // TODO: Implement win condition
    }

    void Game::playerSetup() {
        while (gameState == GameState::PLAYER_SETUP) {
            waitForInput();
            handleSetupClick();
            switch (gameState) {
                case GameState::PLAYER_SETUP: {
                    if (selection2 != nullptr) {
                        // TODO: Switch two selected pieces
                    }
                    render();
                    break;
                }
                case GameState::SWITCHING: {
                    // TODO: Proper condition for exiting function.
                    // currentPlayer.getContainer.size() == 0
                    if (false) {
                        return;
                    }
                    gameState = GameState::PLAYER_SETUP;
                    break;
                }
                case GameState::EXIT:
                case GameState::RESET: {
                    return;
                }
            }
        }
    }

    void Game::playerTurn() {
        while (gameState == GameState::PLAYER_TURN) {
            waitForInput();
            handleTurnClick();
            switch (gameState) {
                case GameState::SWITCHING: {
                    // TODO: Create PlayerMove object
                    return;
                }
                case GameState::EXIT:
                case GameState::RESET: {
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
        Uint32 timePassed;
        SDL_Event e;
        bool resume = false;
        while (!resume) {
            timePassed = SDL_GetTicks();
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    gameState = GameState::EXIT;
                    resume = true;
                }
                if (e.type == SDL_MOUSEBUTTONUP) {
                    SDL_GetMouseState(&mouse.x, &mouse.y);
                    resume = true;
                }
            }
            SDL_RenderClear(Resources::getInstance()->getRenderer());
            render();
            // wait until the time declared in timestep passes
            while(timePassed + timestep > SDL_GetTicks()){
                SDL_Delay(0);
            }
        }
    }

    void Game::render() {
        // Update the screen - last line
        SDL_RenderPresent(Resources::getInstance()->getRenderer());
    }
}
