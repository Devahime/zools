#include <iostream>
#include "Player/Player.h"
#include "GameLogic/Game.h"
#include "GameLogic/Builder.h"
#include <unistd.h>


int main() {
    //Creation of builder
    GameLogic::Builder* builder = new GameLogic::Builder();

    //building the game and returining it to object game here in main
    GameLogic::Game* game = builder->buildGame();

    bool gameRunning = true;
    char input;

    //while (read(STDIN_FILENO, &input, 1) == 1 && input != !'q');

    /*while (gameRunning) {
        std::cin >> input;
        game->checkForAction(input);

    }*/


    /*game->printPlayer();
    game->clearScreen();
    std::cout << "yoooo" << std::endl;
    std::cout << "yoooo" << std::endl;
    game->clearScreen();
    char d;
    std::cin >> d; */

    return 0;
}


