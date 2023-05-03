//
// Created by xkapp on 21.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_RELIC_H
#define ZOOLS2023_XKADERK2_RELIC_H

#include <string>
#include "Item.h"

namespace Entities {
    class Relic : public Item {
        /**
         * Child of class Item.
         * Player can equip relic into his relic slot giving him health and strenght bonus.
         */

        int m_healthBonus;
        int m_stenghtBonus;

    public:

        Relic(std::string name, std::string info, int healthBonus, int strenghtBonus);

        int getHealthBonus();

        int getStrenghtBonus();
    };

}








#endif //ZOOLS2023_XKADERK2_RELIC_H
