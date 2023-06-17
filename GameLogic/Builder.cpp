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
    Game* game = new GameLogic::Game(buildPlayer(), buildLevel());
    return game;
}

Player::Player *GameLogic::Builder::buildPlayer() {
    std::string userInput;
    std::cout << "Please enter your name: ";
    std::cin >>userInput;
    Player::Player* player = new Player::Player(userInput);
    auto inventory = player->getPlayerInvenotry();
    inventory->addItem(new Entities::Consumable("small potion","sweet like honey",15));
    inventory->addItem(new Entities::Weapon("Stick", "the might of wud",15));
    return player;
}

Map::Level *GameLogic::Builder::buildLevel() {

    std::vector<Map::Tile*> tileEntities0;
    std::vector<Map::Tile*> tileEntities1;
    std::vector<Map::Tile*> tileEntities2;
    std::vector<Map::Tile*> tileEntities3;
    std::vector<Map::Tile*> tileEntities4;
    std::vector<Map::Tile*> tileEntities5;
    std::vector<Map::Tile*> tileEntities6;
    std::vector<Map::Tile*> tileEntities7;
    std::vector<Map::Tile*> tileEntities8;
    std::vector<Map::Tile*> tileEntities9;

    Map::Tile* W = new Map::Wall(); tileEntities0.push_back(W);
    Map::Tile* F = new Map::Floor(); tileEntities0.push_back(F);

    Entities::Enemy* enemy1 = new Entities::Enemy("Skeletonus", 50, 10, 10);
    enemy1->addItemDrop(new Entities::Consumable("Dirty water", "its advised to not drink this", 5));
    Map::Tile* E1 = new Map::EnemyTile(enemy1);

    Entities::Item* item1 = new Entities::Armor("dirt helmet", "Wait, this works?", 5);
    Map::Tile* I1 = new Map::ItemTile(item1);

    //room0
    Map::Tile* D1 = new Map::Door(1, true); tileEntities0.push_back(D1);
    Map::Map* map0 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, I1, F, F, F, F, F, E1, F, F, D1},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities0, new Map::Point{1, 3}, new Map::Point{11,3});

    //room1
    Map::Tile* D2 = new Map::Door(0, false); tileEntities1.push_back(D2);
    Map::Tile* D3 = new Map::Door(2, true); tileEntities1.push_back(D3);
    Map::Map* map1 = new Map::Map(
            {{W,  W, W, W, W, W, W, W, W, W, W, W, W},
             {W,  F, F, F, F, F, F, F, F, F, F, F, W},
             {W,  F, F, F, F, F, F, F, F, F, F, F, W},
             {D2, F, F, F, F, F, F, F, F, F, F, F, W},
             {W,  F, F, F, F, F, F, F, F, F, F, F, W},
             {W,  F, F, F, F, F, F, F, F, F, F, F, W},
             {W,  W, W, W, D3, W, W, W, W, W, W, W, W}
            }, tileEntities1,new Map::Point{1, 3},new Map::Point{4, 5});

    //room2
    Map::Tile* D4 = new Map::Door(1, false); tileEntities2.push_back(D4);
    Map::Tile* D5 = new Map::Door(3, true); tileEntities2.push_back(D5);
    Map::Map* map2 = new Map::Map(
            {{W, W, W, W, D4, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, D5},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities2, new Map::Point{4, 1}, new Map::Point{11, 5});

    //room3
    Map::Tile* D6 = new Map::Door(2, false); tileEntities3.push_back(D6);
    Map::Tile* D7 = new Map::Door(4, true); tileEntities3.push_back(D7);
    Map::Map* map3 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, D7},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {D6, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities3, new Map::Point{1, 5}, new Map::Point{11, 1});

    //room4
    Map::Tile* D8 = new Map::Door(3, false); tileEntities4.push_back(D8);
    Map::Tile* D9 = new Map::Door(5, true); tileEntities4.push_back(D9);
    Map::Map* map4 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, D9, W, W, W},
             {D8, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities4, new Map::Point{1, 1}, new Map::Point{9, 1});

    //room5
    Map::Tile* D10 = new Map::Door(4, false); tileEntities5.push_back(D10);
    Map::Tile* D11 = new Map::Door(6, true); tileEntities5.push_back(D11);
    Map::Map* map5 = new Map::Map(
            {{W, W, D11, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, D10, W, W, W}
            }, tileEntities5, new Map::Point{9, 5}, new Map::Point{2, 1});

    //room6
    Map::Tile* D12 = new Map::Door(5, false); tileEntities6.push_back(D12);
    Map::Tile* D13 = new Map::Door(7, true); tileEntities6.push_back(D13);
    Map::Map* map6 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, D13},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, D12, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities6, new Map::Point{2, 5}, new Map::Point{2, 11});

    //room 7 (boss room? naa later)
    Map::Tile* D14 = new Map::Door(6, false); tileEntities7.push_back(D14);
    Map::Tile* D15 = new Map::Door(8, true); tileEntities7.push_back(D15);
    Map::Map* map7 = new Map::Map(
            {{W, W, W, W, W, D15, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {D14, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities7, new Map::Point{1, 3}, new Map::Point{5, 1});

    //room 8
    Map::Tile* D16 = new Map::Door(7, false); tileEntities8.push_back(D16);
    Map::Tile* D17 = new Map::Door(9, true); tileEntities8.push_back(D17);
    Map::Map* map8 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, D17},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, D16, W, W, W, W, W, W, W}
            }, tileEntities8, new Map::Point{5, 5}, new Map::Point{11, 3});

    //room 9 - boss room?
    Map::Tile* D18 = new Map::Door(8, false); tileEntities9.push_back(D18);
    Map::Tile* D19 = new Map::Door(10, true); tileEntities9.push_back(D19);
    Map::Map* map9 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {D18, F, F, F, F, F, F, F, F, F, F, F, D19},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities9, new Map::Point{1, 3}, new Map::Point{11, 3});

    Map::Level* level = new Map::Level("Dungeon 1", {map0, map1, map2, map3, map4, map5, map6, map7, map8, map9});
    return level;

}