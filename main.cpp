#include <iostream>
#include "Player/Player.h"
#include "GameLogic/Game.h"
#include "GameLogic/Builder.h"
#include <unistd.h>
#include "conio.h"
#include "math.h" //debug


int main() {
    //debug
    //std::cout << 15 + round(10*0.9);


    //Creation of builder
    GameLogic::Builder* builder = new GameLogic::Builder();

    //building the game and returining it to object game here in main
    //buildGame() calls function where user input for his name is required
    GameLogic::Game* game = builder->buildGame();

    game->clearScreen();



    //Deleting the builder class as it is no longer necessary 
    delete builder;

    bool gameRunning = true;
    bool playerAlive = true;
    char input;


    game->printTutorial();

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

    game->newMapSetup(true);
    game->printGameScreen();
    //main game loop
    while (gameRunning and playerAlive) {


        input = _getch();
        game->clearScreen();
        gameRunning = game->checkForAction(input);

        if (!game->isPlayerAlive()) {
            playerAlive = false;
        }

    }


    if (gameRunning == false and playerAlive == true) {
        std::cout << "You ended the game, press any key to exit the aplication";
        input = _getch();
    } else {
        std::cout << "You died! \nPress any key to exit!" << std::endl;
        input = _getch();
    }


    /*game->printPlayer();
    game->clearScreen();
    std::cout << "yoooo" << std::endl;
    std::cout << "yoooo" << std::endl;
    game->clearScreen();
    char d;
    std::cin >> d; */

    delete game;

    return 0;

}


