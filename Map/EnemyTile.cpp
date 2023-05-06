//
// Created by xinsanic on 28.04.2023.
//

#include "EnemyTile.h"
#include <iostream>

Map::EnemyTile::EnemyTile(Entities::Enemy *enemy) {
    m_enemy = enemy;
    m_tileType = TileType::EnemyTileType;
}

void Map::EnemyTile::print() {
    std::cout << "E";
}

Entities::Enemy *Map::EnemyTile::getEnemy() {
    return m_enemy;
}
