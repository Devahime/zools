//
// Created by xinsanic on 27.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_MAP_H
#define ZOOLS2023_XKADERK2_MAP_H
#include <string>
#include <vector>
#include "Tile.h"

namespace Map{
    class Map {
    private:
        std::string m_mapName;
        std::vector<std::vector<Tile*>> m_tiles;
        //Map::Point* m_entryPoint;
        //Map::Point* m_exitPoint;
    public:
        Map(std::vector<std::vector<Tile*>>);
        ~Map();

        Tile* getTile(int x, int y);

        void replaceTile(int x, int y, Tile* tile);

        void print();

    };
}

#endif //ZOOLS2023_XKADERK2_MAP_H
