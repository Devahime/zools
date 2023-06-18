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



    //room0
    Entities::Enemy* enemy0 = new Entities::Enemy("Skeletonus", 50, 10, 10);
    enemy0->addItemDrop(new Entities::Consumable("Dirty water", "its advised not to drink this", 5));
    Map::Tile* E0 = new Map::EnemyTile(enemy0);

    Entities::Item* item0 = new Entities::Armor("dirt helmet", "Wait, it works?", 5);
    Map::Tile* A0 = new Map::ItemTile(item0);

    Map::Tile* D1 = new Map::Door(1, true); tileEntities0.push_back(D1);
    Map::Map* map0 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, A0, F, F, F, F, F, E0, F, F, D1},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities0, new Map::Point{1, 3}, new Map::Point{11,3});

    //room1
    Entities::Enemy* enemy1 = new Entities::Enemy("Poisonous spider", 40, 20, 15);
    Map::Tile* E1 = new Map::EnemyTile(enemy1);

    Entities::Item* item1 = new Entities::Weapon("Sharp stick", "Wish I had some marshmallows..", 15);
    Map::Tile* W1 = new Map::ItemTile(item1);

    Map::Tile* D2 = new Map::Door(0, false); tileEntities1.push_back(D2);
    Map::Tile* D3 = new Map::Door(2, true); tileEntities1.push_back(D3);
    Map::Map* map1 = new Map::Map(
            {{W,  W, W, W, W, W, W, W, W, W, W, W, W},
             {W,  F, F, W, F, F, F, F, F, W, F, F, W},
             {W,  F, F, F, F, F, F, F, F, F, W1, F, W},
             {D2, F, F, F, E1, F, F, F, F, F, F, F, W},
             {W,  F, F, F, F, F, F, W, F, F, F, F, W},
             {W,  F, F, F, F, F, F, W, F, F, F, F, W},
             {W,  W, W, W, D3, W, W, W, W, W, W, W, W}
            }, tileEntities1,new Map::Point{1, 3},new Map::Point{4, 5});

    //room2
    Entities::Enemy* enemy2 = new Entities::Enemy("Centipede", 50, 20, 20);
    Map::Tile* E2 = new Map::EnemyTile(enemy2);

    Entities::Item* item2 = new Entities::Consumable("Centipede juice", "It smells awful", 15);
    Map::Tile* C2 = new Map::ItemTile(item2);

    Entities::Item* item2a = new Entities::Relic("Sapphire ring", "It's shiny!", 10, 10 );
    Map::Tile* R2 = new Map::ItemTile(item2a);

    Map::Tile* D4 = new Map::Door(1, false); tileEntities2.push_back(D4);
    Map::Tile* D5 = new Map::Door(3, true); tileEntities2.push_back(D5);
    Map::Map* map2 = new Map::Map(
            {{W, W, W, W, D4, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, W, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, C2, W},
             {W, W, W, F, F, F, F, F, F, F, F, F, W},
             {W, F, R2, F, F, F, F, F, W, F, E2, F, W},
             {W, F, F, F, F, W, W, F, W, F, F, F, D5},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities2, new Map::Point{4, 1}, new Map::Point{11, 5});

    //room3
    Entities::Enemy* enemy3 = new Entities::Enemy("Zombie mice", 60, 20, 20);
    Map::Tile* E3 = new Map::EnemyTile(enemy3);

    Entities::Item* item3 = new Entities::Armor("Leather vest", "Lookin' fancy", 15);
    Map::Tile* A3 = new Map::ItemTile(item3);

    Entities::Item* item3a = new Entities::Relic("Teddy bear", "How could it get here..?", 15, 15);
    Map::Tile* R3 = new Map::ItemTile(item3a);

    Map::Tile* D6 = new Map::Door(2, false); tileEntities3.push_back(D6);
    Map::Tile* D7 = new Map::Door(4, true); tileEntities3.push_back(D7);
    Map::Map* map3 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, W, F, F, F, E3, F, W, F, F, F, D7},
             {W, F, R3, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, W, W, W},
             {W, F, F, F, F, W, F, F, A3, F, F, F, W},
             {D6, F, F, F, F, W, F, F, F, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities3, new Map::Point{1, 5}, new Map::Point{11, 1});

    //room4
    Entities::Enemy* enemy4 = new Entities::Enemy("Necromancer", 70, 30, 30);
    Map::Tile* E4 = new Map::EnemyTile(enemy4);

    Entities::Item* item4 = new Entities::Consumable("Holy water", "Finally something drinkable", 25);
    Map::Tile* C4 = new Map::ItemTile(item4);

    Entities::Item* item4a = new Entities::Weapon("Phoenix bow", "It looks..majestic.", 35);
    Map::Tile* W2 = new Map::ItemTile(item4a);

    Map::Tile* D8 = new Map::Door(3, false); tileEntities4.push_back(D8);
    Map::Tile* D9 = new Map::Door(5, true); tileEntities4.push_back(D9);
    Map::Map* map4 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, D9, W, W, W},
             {D8, F, F, F, F, W2, W, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, W, W, F, F, F, F, F, E4, F, F, F, W},
             {W, F, F, F, F, F, W, W, W, F, F, F, W},
             {W, F, F, C4, F, F, F, F, W, F, F, F, W},
             {W, W, W, W, W, W, W, W, W, W, W, W, W}
            }, tileEntities4, new Map::Point{1, 1}, new Map::Point{9, 1});

    //room5
    Entities::Enemy* enemy5 = new Entities::Enemy("Dark witch", 70, 30, 30);
    Map::Tile* E5 = new Map::EnemyTile(enemy5);

    Entities::Item* item5 = new Entities::Relic("Opal amulet", "It shall protect you", 25, 20);
    Map::Tile* R5 = new Map::ItemTile(item5);

    Map::Tile* D10 = new Map::Door(4, false); tileEntities5.push_back(D10);
    Map::Tile* D11 = new Map::Door(6, true); tileEntities5.push_back(D11);
    Map::Map* map5 = new Map::Map(
            {{W, W, D11, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, W, F, F, F, W},
             {W, W, F, F, F, F, F, F, W, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, E5, F, F, W, F, F, F, F, F, F, W},
             {W, F, F, F, F, W, F, F, F, F, F, R5, W},
             {W, W, W, W, W, W, W, W, W, D10, W, W, W}
            }, tileEntities5, new Map::Point{9, 5}, new Map::Point{2, 1});

    //room6 - skončila sem tady (pro mé zítřejší já)
    Entities::Enemy* enemy6 = new Entities::Enemy("Suspicious tree", 80, 40, 25);
    Map::Tile* E6 = new Map::EnemyTile(enemy6);

    Entities::Item* item6a = new Entities::Armor("Chainmail armor", "It's pretty comfy", 25);
    Map::Tile* A6 = new Map::ItemTile(item6a);

    Map::Tile* D12 = new Map::Door(5, false); tileEntities6.push_back(D12);
    Map::Tile* D13 = new Map::Door(7, true); tileEntities6.push_back(D13);
    Map::Map* map6 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W, W},
             {W, F, F, F, F, F, F, F, F, F, F, A6, W},
             {W, F, F, F, F, F, F, F, F, F, F, F, W},
             {W, F, F, F, F, F, F, F, F, E6, F, F, D13},
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