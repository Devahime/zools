#include <iostream>
#include "Player/Player.h"
#include "GameLogic/Game.h"
#include "GameLogic/Builder.h"
#include "conio.h"


int main() {


    //Creation of builder
    GameLogic::Builder* builder = new GameLogic::Builder();

    //building the game and retuning it to object game here in main
    //buildGame() calls function where user input for his name is required
    GameLogic::Game* game = builder->buildGame();

    game->clearScreen();



    //Deleting the builder class as it is no longer necessary 
    delete builder;

    bool gameRunning = true;
    bool playerAlive = true;
    char input;

    game->printTutorial();

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


    if (gameRunning == false and playerAlive == true and !game->isGameCompleted()) {
        std::cout << "You ended the game, press any key to exit the application";
        input = _getch();

    } else if (gameRunning == false and game->isGameCompleted()){
        //game proceeds to turn off
    } else {
        std::cout << "You died! \nPress any key to exit!" << std::endl;
        input = _getch();
    }


    delete game;

    return 0;
}


