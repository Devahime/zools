//
// Created by xinsanic on 28.04.2023.
//

#include "Wall.h"
#include <iostream>

Map::Wall::Wall() {
    m_tileType = TileType::WallType;
}

void Map::Wall::print() {
    std::cout << "#";
}
