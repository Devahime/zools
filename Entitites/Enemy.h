//
// Created by xkapp on 17.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ENEMY_H
#define ZOOLS2023_XKADERK2_ENEMY_H

#include <string>
#include <vector>
#include "Item.h"
#include "../Player/Ability.h"

namespace Entities {
    class Enemy {
    private:
        std::string m_name;
        int m_health;
        int m_armor;
        int m_strenght;
        std::vector<Player::Ability *> m_abilites;
        Item *m_itemDrop;

    public:
        Enemy(std::string name, int health, int armor, int strenght);

        void addItemDrop(Item* item);

        void addAbility(Player::Ability* ability);

        int getHealth();

        int getArmor();

        int getStrenght();

        bool isAlive();
    };



}







#endif //ZOOLS2023_XKADERK2_ENEMY_H
