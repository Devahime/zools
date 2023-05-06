//
// Created by xinsanic on 28.04.2023.
//

#include "Door.h"
#include "Map.h"
#include "TileType.h"
#include "Tile.h"
#include <iostream>

Map::Door::Door(){
    m_tileType = TileType::DoorType;

}

int Map::Door::getTargetRoom() {
    return 0;
}

void Map::Door::print() {
    std::cout << "D";
}
