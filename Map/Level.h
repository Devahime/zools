//
// Created by xkapp on 30.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_LEVEL_H
#define ZOOLS2023_XKADERK2_LEVEL_H
#include <string>
#include "Map.h"
#include <vector>

namespace Map {
    class Level {
        std::string m_levelName;
        std::vector<Map*> m_maps;

    public:
        Level(std::string name, std::vector<Map*> maps);

        Map* getMap(int mapNumber);

        int getLevelSize();

        std::string getLevelName();
    };
}


#endif //ZOOLS2023_XKADERK2_LEVEL_H
