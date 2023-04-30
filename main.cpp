#include <iostream>
#include "Player/Player.h"
#include "GameLogic/Game.h"
#include "GameLogic/Builder.h"
#include <unistd.h>
#include "conio.h"


int main() {
    //Creation of builder
    GameLogic::Builder* builder = new GameLogic::Builder();

    //building the game and returining it to object game here in main
    GameLogic::Game* game = builder->buildGame();

    //Deleting the builder class as it is no longer necessary
    delete builder;

    bool gameRunning = true;
    char input;

    //while (read(STDIN_FILENO, &input, 1) == 1 && input != !'q');

   /* while (true) {
        input = _getch();
        game->clearScreen();
        if (input == 'd') {
            std::cout << "####" << std::endl
            << "# P#" << std::endl
            << "####" << std::endl;
        } else if (input == 'a') {
            std::cout << "####" << std::endl
            << "#P #" << std::endl
            << "####" << std::endl;
        }
    }*/   //debug


    while (gameRunning) {


        input = _getch();
        game->clearScreen();
        gameRunning = game->checkForAction(input);

    }




    std::cout << "You died the game, press any key to die the game completely" << std::endl;
    input = _getch();

    /*game->printPlayer();
    game->clearScreen();
    std::cout << "yoooo" << std::endl;
    std::cout << "yoooo" << std::endl;
    game->clearScreen();
    char d;
    std::cin >> d; */

    return 0;
}


