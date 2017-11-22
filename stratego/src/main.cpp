#include <iostream>
#include "Game.h"

using namespace stratego;

int main() {
    Game game;

    bool quit = false;
    while (!quit) {
        // Run a whole game from setup to finish.
        switch (game.run()) {
            case GameState::PLAYER_WIN: {
                // TODO: Congratulate and ask for new game input graphically.
                std::string input;
                std::cout << "Do you want to play again? (yes/no)" << std::endl;
                std::cin >> input;
                if (input != "yes") {
                    quit = true;
                }
                break;
            }
            case GameState::RESET: {
                break;
            }
            case GameState::EXIT: {
                quit = true;
                break;
            }
            default: {
                std::cout << "GameState returned from game.run() was unexpected!";
                quit = true;
            }
        }
    }

    return 0;
}