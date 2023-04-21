//
// Created by xkapp on 21.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_CONSUMABLE_H
#define ZOOLS2023_XKADERK2_CONSUMABLE_H

#include <string>
#include "Item.h"

namespace Entities {
    class Consumable : public Item {
        /**
         * Child of class Item.
         * Player can use this tem to replenish health.
         */

        int m_replenishmentValue;

    public:
        Consumable(std::string name, std::string info, int replenishmentValue);

        int getReplenishemntValue();
    };
}




#endif //ZOOLS2023_XKADERK2_CONSUMABLE_H
