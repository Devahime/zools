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
        Player::Ability* m_ability;
        Item *m_itemDrop;
        int m_maxHealth;

    public:
        Enemy(std::string name, int health, int armor, int strenght);

        ~Enemy();

        void addItemDrop(Item* item);

        int getHealth();

        int getArmor();

        int getStrenght();

        bool isAlive();

        int getMaxHealth();

        std::string getName();

        void takeDamage(int damage);

        Player::Ability* getAbility();

        Entities::Item* dropItem();
    };



}







#endif //ZOOLS2023_XKADERK2_ENEMY_H
