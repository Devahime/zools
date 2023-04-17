//
// Created by xkapp on 16.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_PLAYER_H
#define ZOOLS2023_XKADERK2_PLAYER_H

#include <string>
#include <vector>



namespace Player {
    class Player {
    private:
        std::string m_name;
        int m_maxHealth;
        int m_health;
        int m_armor;
        int m_strenght;
        std::vector<Ability *> m_abilities;
        Armor *m_armorSlot;
        Relic *m_relicSlot;
        Weapon *m_weaponSlot;
        std::vector<Item *> m_inventory;

    public:

        Player(std::string name);

        int getHealth();

        int getStrenght();

        int getArmor();

        void equipArmor(Armor *armor);

        void dropArmor();

        void equipRelic(Relic *relic);

        void dropRelic();

        void equipWeapon(Weapon *weapon);

        void dropWeapon();

        string getName();

        void takeDamage(int damage);

        bool isAlive();
    };
}











#endif //ZOOLS2023_XKADERK2_PLAYER_H
