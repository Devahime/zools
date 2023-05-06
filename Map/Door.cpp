//
// Created by xinsanic on 28.04.2023.
//

#include "Door.h"
#include "Map.h"
#include "TileType.h"
#include "Tile.h"
#include <iostream>

Map::Door::Door(int targetRoom){
    m_tileType = TileType::DoorType;
    m_targetRoom = targetRoom;
}

int Map::Door::getTargetRoom() {
    return m_targetRoom;
}

void Map::Door::print() {
    std::cout << "D";
}
