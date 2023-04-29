//
// Created by xkapp on 21.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_WEAPON_H
#define ZOOLS2023_XKADERK2_WEAPON_H


#include "Item.h"
#include <string>


namespace Entities {
    class Weapon : public Item {
        /**
         * Child of class Item.
         * Player can equip weapon into his weapon slot and will recieve damage bonus in each of his attacks
         */

        int m_damage;

    public:
        Weapon(std::string name, std::string info, int damage);

        int getDamage();

    };
}




#endif //ZOOLS2023_XKADERK2_WEAPON_H
