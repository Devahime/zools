//
// Created by xinsanic on 28.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ENEMYTILE_H
#define ZOOLS2023_XKADERK2_ENEMYTILE_H
#include "../Entitites/Enemy.h"

namespace Map{
    class EnemyTile {
    private:
        Entities::Enemy* enemy;
    public:
        EnemyTile(Entities:: Enemy* enemy);
        void print();

    };
}


#endif //ZOOLS2023_XKADERK2_ENEMYTILE_H
