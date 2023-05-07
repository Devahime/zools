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


    //pro každou mapu (místnost) si musíš vytvořit vector entit (vector tilů)
    std::vector<Map::Tile*> tileEntities0;
    std::vector<Map::Tile*> tileEntities1;
    //pak vytvoříš políčka který budou všude a budou jen jednou, to znamená podlahu a zdi
    //každé políčko co vytvoříš musíš potom dát do tile lustu příslušní mapy
    Map::Tile* W = new Map::Wall(); tileEntities0.push_back(W); //<- tady toto
    Map::Tile* F = new Map::Floor(); tileEntities0.push_back(F);


    //dveře do další místnosti budou mít číslo mapy o jedno vyšší než mapa ve které je, pokud dveře vedou do další mapy isExit je true
    Map::Tile* D1 = new Map::Door(1, true); tileEntities0.push_back(D1); //tile list 0 takže 0. mapa


//pokud dveře vedou do předchozí mapy, bude traget room o jedno menší než současná mapa a isExit bude false
    Map::Tile* D2 = new Map::Door(0, false); tileEntities1.push_back(D2); //tile list 1 takže 1. mapa

    Entities::Enemy* enemy1 = new Entities::Enemy("Skeletonus", 50, 10, 10);
    enemy1->addItemDrop(new Entities::Consumable("Dirty water", "it as advised to not drink this", 5));

    Map::Tile* E1 = new Map::EnemyTile(enemy1);




//pak vytvoříš mapy po jednom
    Map::Map* map1 = new Map::Map(
            {{W, W, W, W, W, W, W, W, W, W, W, W,},
                {W, F, F, F, F, F, F, F, F, F, F, W},
                {W, F, F, F, F, F, F, F, F, F, F, W},
                {W, F, F, F, F, F, F, F, F, E1, F, D1},
                {W, F, F, F, F, F, F, F, F, F, F, W},
                {W, F, F, F, F, F, F, F, F, F, F, W},
                {W, W, W, W, W, W, W, W, W, W, W, W,}
                //je potřeba dávat pozor kam dáváš pointy. Entry point je místo kde se hráč objěví na začátku nebo když přijde z předchozí místnosti
                // exit point je to kde se hráč objeví když přijde z další místnosti zpět do téhle
             }, tileEntities0, new Map::Point{1, 3}, new Map::Point{10,3});
            //při vytváření mapy nezapomeň na to tam hodit ty tileEntitites

            //tady opakuješ to samý
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