//
// Created by xinsanic on 28.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ENEMYTILE_H
#define ZOOLS2023_XKADERK2_ENEMYTILE_H
#include "../Entitites/Enemy.h"
#include "Tile.h"
#include "TileType.h"

namespace Map{
    class EnemyTile : public Tile{
    private:
        Entities::Enemy* m_enemy;
    public:
        EnemyTile(Entities:: Enemy* enemy);
        void print();
        Entities::Enemy* getEnemy();
    };
}


#endif //ZOOLS2023_XKADERK2_ENEMYTILE_H
