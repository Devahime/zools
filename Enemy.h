//
// Created by xkapp on 17.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ENEMY_H
#define ZOOLS2023_XKADERK2_ENEMY_H

#include <string>
#include <vector>

namespace GameLogic {
    class Enemy {
    private:
        std::string m_name;
        int m_health;
        int m_armor;
        int m_strenght;
        std::vector<Ability *> m_abilites;
        Item *m_itemDrop;

    public:
        Enemy(std::string name, int health, int armor, int strenght);

        void addItemDrop(Item* item);

        void addAbility(Ability* ability);

        int getHealth();

        int getArmor();

        int getStrenght();

        bool isAlive();
    };



}







#endif //ZOOLS2023_XKADERK2_ENEMY_H
