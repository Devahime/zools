//
// Created by xkapp on 29.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_GAME_H
#define ZOOLS2023_XKADERK2_GAME_H

//#include "../Map/Level.h"
#include "../Player/Player.h"
#include "Combat.h"

namespace GameLogic {
    class Game {
        //Map::Level* m_level;
        Player::Player* m_player;
        int m_currentMap;
        GameLogic::Combat* m_combat;
    public:
        Game();


        void clearScreen();

        void printMap();

        void printInventory();

        

    };
}





#endif //ZOOLS2023_XKADERK2_GAME_H
