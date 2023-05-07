//
// Created by xinsanic on 28.04.2023.
//

#include "Door.h"
#include "Map.h"
#include "TileType.h"
#include "Tile.h"
#include <iostream>

Map::Door::Door(int targetRoom, bool isExit){
    m_tileType = TileType::DoorType;
    m_targetRoom = targetRoom;
    m_isExitDoor = isExit;
}

int Map::Door::getTargetRoom() {
    return m_targetRoom;
}

void Map::Door::print() {
    std::cout << "D";
}

bool Map::Door::isExitDoor() {
    return m_isExitDoor;
}