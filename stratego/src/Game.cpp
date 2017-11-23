//
// Created by meszi on 2017.11.21..
//

#include <renderable/clickable/Menu.h>
#include "Game.h"

namespace stratego {

    Game::Game() :
            lastAction(selection1, selection2),
            board(new Board()),
            player1(new Player("P1", PlayerColor::BLUE)),
            player2(new Player("P2", PlayerColor::RED)),
            selection1(new Selection()),
            selection2(new Selection()) {
        board->setPosition(0, 0);
        board->initPiecePositions();
        player1->getPieceContainer()->setPosition(640, 128);
        player2->getPieceContainer()->setPosition(640, 128);
        player1->initContainer(player1);
        player2->initContainer(player2);
        player1->setPosition(640, 64);
        player2->setPosition(640, 64);
        sptr<Menu> menu(new Menu({640, 0}));
        renderObjects.emplace_back(menu);
        clickObjects.emplace_back(menu);
        renderObjects.emplace_back(board);
        clickObjects.emplace_back(board);
        renderObjects.emplace_back(player1);
        renderObjects.emplace_back(player2);
        clickObjects.emplace_back(player1->getPieceContainer());
        clickObjects.emplace_back(player2->getPieceContainer());
        renderObjects.emplace_back(selection1);
        renderObjects.emplace_back(selection2);
    }

    GameState Game::run() {
        reset();
        bool quit = false;
        while (!quit) {
            render();
            switch (gameState) {
                case GameState::PLAYER_TURN: {
                    playerTurn();
                    if (gameState == GameState::RESET || gameState == GameState::EXIT) {
                        break;
                    }
                    board->flipFaceDown();
                    if (lastAction.isAttack()) {
                        selection1->faceUp();
                        selection2->faceUp();
                    }
                    switchPlayer();
                    break;
                }
                case GameState::SWITCHING: {
                    while (gameState == GameState::SWITCHING) {
                        waitForInput();
                        ClickActionType clickType = determineClickType();
                        if (clickType == ClickActionType::RESET) {
                            gameState = GameState::RESET;
                            break;
                        }
                        if (clickType == ClickActionType::EXIT) {
                            gameState = GameState::EXIT;
                            break;
                        }
                        if (clickType == ClickActionType::NEXT) {
                            gameState = GameState::PLAYER_TURN;
                            board->flipFaceUpForPlayer(currentPlayer);
                        }
                        if (gameState == GameState::PLAYER_TURN) {
                            lastAction.execute(board);
                            checkForWin();
                            board->flipFaceUpForPlayer(currentPlayer);
                        }
                    }
                    break;
                }
                case GameState::EXIT:
                case GameState::PLAYER_WIN:
                case GameState::RESET: {
                    quit = true;
                }
            }
        }
        return gameState;
    }

    void Game::checkForWin() {
        if (currentPlayer->checkForFlag()) gameState = GameState::PLAYER_WIN;
    }

    void Game::playerSetup() {
        while (gameState == GameState::PLAYER_SETUP) {
            waitForInput();
            handleSetupClick();
            switch (gameState) {
                case GameState::PLAYER_SETUP: {
                    if (selection2->isActive()) {
                        selection1->switchWith(selection2);
                    }
                    render();
                    break;
                }
                case GameState::SWITCHING: {
                    if (currentPlayer->getPieceContainer()->empty()) {
                        return;
                    } else {
                        placePieces(currentPlayer);
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
                    lastAction.setPlayer(currentPlayer);
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
        board->resetPieces();
        gameState = GameState::PLAYER_SETUP;
        currentPlayer = player1;
        currentPlayer->activate();
        player2->deactivate();
        playerSetup();
        if (gameState == GameState::EXIT || gameState == GameState::RESET) return;
        board->flipFaceDown();
        switchPlayer();
        gameState = GameState::PLAYER_SETUP;
        playerSetup();
        if (gameState == GameState::EXIT || gameState == GameState::RESET) return;
        switchPlayer();
        board->flipFaceDown();
        gameState = GameState::SWITCHING;
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
            while (timePassed + timestep > SDL_GetTicks()) {
                SDL_Delay(0);
            }
        }
    }

    void Game::render() {
        for (auto& renderable : renderObjects) {
            renderable->render(gameState);
        }
        // Update the screen - last line
        SDL_RenderPresent(Resources::getInstance()->getRenderer());
    }

    void Game::handleSetupClick() {
        ClickActionType clickType = determineClickType();
        switch (clickType) {
            case ClickActionType::EXIT: {
                gameState = GameState::EXIT;
                return;
            }
            case ClickActionType::RESET: {
                gameState = GameState::RESET;
                return;
            }
            case ClickActionType::NEXT : {
                gameState = GameState::SWITCHING;
                return;
            }
            case ClickActionType::BOARD:
            case ClickActionType::CONTAINER: {
                coord pos;
                sptr<Piece> piece;
                sptr<DisplayMatrix> matrix;
                if (clickType == ClickActionType::BOARD) {
                    matrix = board;
                } else {
                    matrix = currentPlayer->getPieceContainer();
                }
                if (!selection1->isActive()) {
                    pos = matrix->getGridCoordFromMousePosition(mouse);
                    piece = matrix->getPiece(pos);
                    if (piece->getPlayer() == currentPlayer) {
                        selection1->activate(pos, matrix, piece);
                        gameState = GameState::PLAYER_SETUP;
                        return;
                    }
                } else {
                    int minY = currentPlayer == player1 ? 6 : 0;
                    int maxY = currentPlayer == player1 ? 9 : 3;
                    pos = matrix->getGridCoordFromMousePosition(mouse);
                    if (clickType == ClickActionType::BOARD) {
                        if (pos.y < minY || pos.y > maxY) return;
                    }
                    piece = matrix->getPiece(pos);
                    selection2->activate(pos, matrix, piece);
                    gameState = GameState::PLAYER_SETUP;
                    return;
                }
                gameState = GameState::PLAYER_SETUP;
            }
        }
    }

    void Game::handleTurnClick() {
        ClickActionType clickType = determineClickType();
        switch (clickType) {
            case ClickActionType::EXIT: {
                gameState = GameState::EXIT;
                return;
            }
            case ClickActionType::RESET: {
                gameState = GameState::RESET;
                return;
            }
            case ClickActionType::NEXT: {
                gameState = GameState::PLAYER_TURN;
                board->flipFaceUpForPlayer(currentPlayer);
                return;
            }
            case ClickActionType::BOARD: {
                sptr<DisplayMatrix> matrix(board);
                sptr<Piece> piece(matrix->getPiece(matrix->getGridCoordFromMousePosition(mouse)));
                coord pos(matrix->getGridCoordFromMousePosition(piece->getPosition()));
                if (piece->getPlayer() == currentPlayer) {
                    auto type(piece->getType());
                    if (type != PieceType::FLAG && type != PieceType::BOMB) {
                        selection1->activate(pos, matrix, piece);
                    }
                } else {
                    if (selection1->isActive()) {
                        if (piece->getType() != PieceType::WATER) {
                            selection2->activate(pos, matrix, piece);
                            if (board->isValidMove(selection1, selection2)) {
                                gameState = GameState::SWITCHING;
                                return;
                            } else {
                                selection2->deactivate();
                            }
                        }
                        gameState = GameState::PLAYER_TURN;
                    }
                }
            }
        }
    }

    ClickActionType Game::determineClickType() {
        ClickActionType clickType;
        for (auto& clickable : clickObjects) {
            clickType = clickable.get()->evaluateClick(mouse);
            if (clickType != ClickActionType::OUTSIDE) {
                return clickType;
            }
        }
        return ClickActionType::OUTSIDE;
    }

    void Game::switchPlayer() {
        currentPlayer->deactivate();
        if (currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
        currentPlayer->activate();
    }

    void Game::placePieces(sptr<Player>& player) {
        sptr<DisplayMatrix> cont(player->getPieceContainer());
        sptr<DisplayMatrix> bm(board);
        int x = 0;
        int istart = player == player1 ? 6 : 0;
        for (int i = istart; i < istart + 4; ++i) {
            for (int j = 0; j < 10; ++j) {
                auto piece(cont->getPiece(cont->linearToGridCoord(x++)));
                selection1->activate(cont->getGridCoordFromMousePosition(piece->getPosition()), cont, piece);
                selection2->activate({j, i}, bm, bm->getPiece({j, i}));
                selection1->switchWith(selection2);
            }
        }
    }
}
