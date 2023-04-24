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
#include "Consumable.h"



namespace Player {
    class Player {
        /**
         * Class which represent player controlled Character.
         * When making player, the only atribute that needs to be specified is the name.
         */

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
//todo - player coordinates
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

        void useReplenishment(Entities::Consumable *consumable);

        void setHealth(int health); //debug
    };
}











#endif //ZOOLS2023_XKADERK2_PLAYER_H
