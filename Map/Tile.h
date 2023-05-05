//
// Created by xinsanic on 27.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_TILE_H
#define ZOOLS2023_XKADERK2_TILE_H

#include "TileType.h"
#include <string>

namespace Map{
    class Tile {
    protected:
        Map::TileType m_tileType;

    public:
        virtual void print() = 0;
        std::string getType();

    };
}

#endif //ZOOLS2023_XKADERK2_TILE_H
