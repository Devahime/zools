//
// Created by xinsanic on 27.04.2023.
//

#include "Map.h"
#include <string>
#include <iostream>


Map::Map::Map(std::vector<std::vector<Tile *>> tiles, std::vector<Tile*> tileEntities, Point* entryPoint, Point* exitPoint) {
    m_tiles = tiles;
    m_tileEntitites = tileEntities;
    m_entryPoint = entryPoint;
    m_exitPoint = exitPoint;
}

Map::Map::~Map() {
    //todo
}

Map::Tile *Map::Map::getTile(int x, int y) {
    return m_tiles[x][y];
}

void Map::Map::replaceTile(int x, int y, Tile *tile) {
    m_tiles[x][y] = tile;

}

void Map::Map::print() {
    for (int yCordinate = 0; yCordinate < m_tiles.size(); ++yCordinate) {
        for (int xCordinate = 0; xCordinate < m_tiles[yCordinate].size(); ++xCordinate) {
            m_tiles[yCordinate][xCordinate]->print();
        }
        std::cout << "\n";
    }
}

Map::Point* Map::Map::getEntryPoint() {
    return m_entryPoint;
}

Map::Point *Map::Map::getExitPoint() {
    return m_exitPoint;
}
