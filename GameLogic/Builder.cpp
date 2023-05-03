//
// Created by xkapp on 29.04.2023.
//

#include "Builder.h"
#include <string>
#include <iostream>


GameLogic::Builder::Builder() {
    m_game == nullptr;
}

GameLogic::Game *GameLogic::Builder::buildGame() {
    Game* game = new GameLogic::Game(buildPlayer(), new Combat()); //add level


    return game;
}

Player::Player *GameLogic::Builder::buildPlayer() {
    std::string userInput;
    std::cout << "Please write your name: ";
    std::cin >>userInput;
    Player::Player* player = new Player::Player(userInput);
    player->addItem(new Entities::Consumable("small potion","sweet like honey",15));
    player->addItem(new Entities::Weapon("Stick", "the might of wud",15));
    return player;
}