//
// Created by xinsanic on 28.04.2023.
//

#include "ItemTile.h"
#include <iostream>

Map::ItemTile::ItemTile(Entities::Item *item) {
    m_item = item;
    m_tileType = TileType::Item;
}

void Map::ItemTile::print() {
    std::cout << "I";
}

Entities::Item *Map::ItemTile::takeItem() {
    auto item = m_item;
    m_item = nullptr;
    return item;
}

Map::ItemTile::~ItemTile() {
    delete m_item;
}