#include <iostream>
#include "Player/Player.h"
#include "GameLogic/Game.h"
#include "GameLogic/Builder.h"



int main() {
    //Creation of builder
    GameLogic::Builder* builder = new GameLogic::Builder();

    //
    GameLogic::Game* game = builder->buildGame();


    game->printPlayer();
    game->clearScreen();
    std::cout << "yoooo" << std::endl;
    std::cout << "yoooo" << std::endl;
    game->clearScreen();

    return 0;
}


