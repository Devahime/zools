//
// Created by xinsanic on 28.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ITEMTILE_H
#define ZOOLS2023_XKADERK2_ITEMTILE_H
#include "../Entitites/Item.h"

namespace Map{
    class ItemTile {
    private:
        Entities::Item* item;
    public:
        ItemTile(Entities::Item* item);
        void print();
    };
}


#endif //ZOOLS2023_XKADERK2_ITEMTILE_H
