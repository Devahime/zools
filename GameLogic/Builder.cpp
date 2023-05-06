//
// Created by xkapp on 29.04.2023.
//

#include "Builder.h"
#include <string>
#include <iostream>
#include "../Map/Tile.h"
#include "../Map/Wall.h"
#include "../Map/Floor.h"


GameLogic::Builder::Builder() {
    m_game == nullptr;
}

GameLogic::Game *GameLogic::Builder::buildGame() {
    Game* game = new GameLogic::Game(buildPlayer(), new Combat(), buildLevel());


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

Map::Level *GameLogic::Builder::buildLevel() {

    std::vector<Map::Tile*> tileEntities;

    Map::Tile* W = new Map::Wall(); tileEntities.push_back(W);
    Map::Tile* F = new Map::Floor(); tileEntities.push_back(F);




    Map::Map* map1 = new Map::Map(
            {{W, W, W, W},
                {W, F, F, W},
                {W, W, W, W}
             }, tileEntities, new Map::Point{1, 1}, new Map::Point{1,2});


}