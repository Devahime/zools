//
// Created by xinsanic on 28.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ITEMTILE_H
#define ZOOLS2023_XKADERK2_ITEMTILE_H
#include "../Entitites/Item.h"
#include "Tile.h"

namespace Map{
    class ItemTile : public Tile {
    private:
        Entities::Item* item;
    public:
        ItemTile(Entities::Item* item);
        void print();
    };
}


#endif //ZOOLS2023_XKADERK2_ITEMTILE_H
