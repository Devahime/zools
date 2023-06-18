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
    return m_tiles[y][x];
}

void Map::Map::replaceTile(int x, int y, Tile *tile) {
    m_tiles[y][x] = nullptr;
    m_tiles[y][x] = tile;
}

void Map::Map::print() {
    std::cout << "    ";
    for (int yCordinate = 0; yCordinate < m_tiles.size(); ++yCordinate) {
        for (int xCordinate = 0; xCordinate < m_tiles[yCordinate].size(); ++xCordinate) {
            m_tiles[yCordinate][xCordinate]->print();
        }
        std::cout << "\n    ";
    }
}

void Map::Map::swapTiles(int xOrigin, int yOrigin, int xDestination, int yDestination) {
    auto originTile = m_tiles[yOrigin][xOrigin];
    auto destinationTile = m_tiles[yDestination][xDestination];

    //rewrite the destination by origin
    m_tiles[yDestination][xDestination] = originTile;
    //rewrite the origin bydestination
    m_tiles[yOrigin][xOrigin] = destinationTile;
}

Map::Point* Map::Map::getEntryPoint() {
    return m_entryPoint;
}

Map::Point *Map::Map::getExitPoint() {
    return m_exitPoint;
}

bool Map::Map::isItem(int x, int y) {
    if (m_tiles[y][x]->getType() == TileType::Item) {
        return true;
    } else {
        return false;
    }
}

bool Map::Map::isEnemy(int x, int y) {
    if (m_tiles[y][x]->getType() == TileType::EnemyTileType) {
        return true;
    } else {
        return false;
    }
}

bool Map::Map::isDoor(int x, int y) {
    if (m_tiles[y][x]->getType() == TileType::DoorType) {
        return true;
    } else {
        return false;
    }
}

bool Map::Map::isNotWall(int x, int y) {
    if (m_tiles[y][x]->getType() != TileType::WallType) {
        return true;
    } else {
        return false;
    }
}
