#include <iostream>
#include "Game.h"

using namespace stratego;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

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
                game = Game();
                break;
            }
            case GameState::RESET: {
                game = Game();
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

    Resources::releaseResources();
    IMG_Quit();
    SDL_Quit();

    return 0;
}