//
// Created by xkapp on 16.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_PLAYER_H
#define ZOOLS2023_XKADERK2_PLAYER_H

#include <string>
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Relic.h"
#include "Armor.h"
#include "Ability.h"



namespace Player {
    class Player {
    private:
        std::string m_name;
        int m_maxHealth;
        int m_health;
        int m_armor;
        int m_strenght;
        std::vector<Ability *> m_abilities;
        Entities::Armor *m_armorSlot;
        Entities::Relic *m_relicSlot;
        Entities::Weapon *m_weaponSlot;
        std::vector<Entities::Item *> m_inventory;

    public:

        Player(std::string name);

        int getHealth();

        int getStrenght();

        int getArmor();

        void equipArmor(Entities::Armor *armor);

        void dropArmor();

        void equipRelic(Entities::Relic *relic);

        void dropRelic();

        void equipWeapon(Entities::Weapon *weapon);

        int getWeaponDamage();

        void dropWeapon();

        std::string getName();

        void takeDamage(int damage);

        bool isAlive();

        void addAbility(Ability * ability);

        std::vector<Ability*> getAbilities();
    };
}











#endif //ZOOLS2023_XKADERK2_PLAYER_H
