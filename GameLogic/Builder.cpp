//
// Created by xkapp on 29.04.2023.
//

#include "Builder.h"
#include <string>
#include <iostream>
#include "../Map/Tile.h"
#include "../Map/Wall.h"
#include "../Map/Floor.h"
#include "../Map/PlayerTile.h"
#include "../Map/ItemTile.h"
#include "../Map/EnemyTile.h"
#include "../Map/Door.h"
#include "../Entitites/Enemy.h"
#include "../Entitites/Consumable.h"
#include "../Entitites/Relic.h"
#include "../Entitites/Weapon.h"
#include "../Entitites/Armor.h"



GameLogic::Builder::Builder() {
    m_game == nullptr;
}

GameLogic::Game *GameLogic::Builder::buildGame() {
    Game* game = new GameLogic::Game(buildPlayer(), new Combat(), buildLevel());
    return game;
}

Player::Player *GameLogic::Builder::buildPlayer() {
    std::string userInput;
    std::cout << "Please enter your name: ";
    std::cin >>userInput;
    Player::Player* player = new Player::Player(userInput);
    player->addItem(new Entities::Consumable("small potion","sweet like honey",15));
    player->addItem(new Entities::Weapon("Stick", "the might of wud",15));
    return player;
}

Map::Level *GameLogic::Builder::buildLevel() {

    std::vector<Map::Tile*> tileEntities0;
    std::vector<Map::Tile*> tileEntities1;
    std::vector<Map::Tile*> tileEntities2;
    std::vector<Map::Tile*> tileEntities3;
    std::vector<Map::Tile*> tileEntities4;

    Map::Tile* W = new Map::Wall(); tileEntities0.push_back(W);
    Map::Tile* F = new Map::Floor(); tileEntities0.push_back(F);
    Map::Tile* D = new Map::Door(); tileEntities0.push_back(D);

    Entities::Enemy* enemy1 = new Entities::Enemy("Skeletonus", 50, 10, 10);
    enemy1->addItemDrop(new Entities::Consumable("Dirty water", "its advised to not drink this", 5));

    Map::Tile* E1 = new Map::EnemyTile(enemy1);

    Map::Map* map0 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, E1, F, F, D1},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities0, new Map::Point{1, 3}, new Map::Point{11,3});
    Map::Tile* D1 = new Map::Door(1, true); tileEntities0.push_back(D1);
    
    Map::Map* map2 = new Map::Map(
            {{W,  W, W, W, W, W, W, W, W, W, W, W,},
             {W,  F, F, F, F, F, F, F, F, F, F, W},
             {W,  F, F, F, F, F, F, F, F, F, F, W},
             {D2, F, F, F, F, F, F, F, F, F, F, W},
             {W,  F, F, F, F, F, F, F, F, F, F, W},
             {W,  F, F, F, F, F, F, F, F, F, F, W},
             {W,  W, W, W, W, W, W, W, W, W, W, W,}
            }, tileEntities1,new Map::Point{1, 3},new Map::Point{10, 3});

    //potom uděláš level, kde dáš nízev levelu, a pak vector map jak jdou po sobě jak vidíš níže
    Map::Level* level = new Map::Level("Dungeon 1", {map1, map2});

    
    return level;
}