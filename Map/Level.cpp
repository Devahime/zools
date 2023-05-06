//
// Created by xkapp on 06.05.2023.
//

#include "Level.h"

Map::Level::Level(std::string name, std::vector<Map *> maps) {
    m_levelName = name;
    m_maps = maps;
}

Map::Map *Map::Level::getMap(int mapNumber) {
    return m_maps[mapNumber];
}

int Map::Level::getLevelSize() {
    return m_maps.size();
}

std::string Map::Level::getLevelName() {
    return m_levelName;
}