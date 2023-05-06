//
// Created by xinsanic on 28.04.2023.
//

#include "Floor.h"
#include <iostream>

Map::Floor::Floor() {
    m_tileType = TileType::FloorType;
}

void Map::Floor::print() {
    std::cout << " ";
}
