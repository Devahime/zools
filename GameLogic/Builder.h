//
// Created by xkapp on 29.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_BUILDER_H
#define ZOOLS2023_XKADERK2_BUILDER_H

#include "Game.h"
#include "../Map/Level.h"

namespace GameLogic {
    class Builder {
    private:
        Game* m_game;

        Player::Player* buildPlayer();

        Map::Level* buildLevel();

    public:
        Builder();

        Game* buildGame();

    };
}




#endif //ZOOLS2023_XKADERK2_BUILDER_H
