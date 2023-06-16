//
// Created by xkapp on 16.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_PLAYER_H
#define ZOOLS2023_XKADERK2_PLAYER_H

#include <string>
#include <vector>
#include <array>
#include "../Entitites/Item.h"
#include "../Entitites/Weapon.h"
#include "../Entitites/Relic.h"
#include "../Entitites/Armor.h"
#include "Ability.h"
#include "../Entitites/Consumable.h"
#include "../Map/Point.h"
#include "PlayerInventory.h"



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
        PlayerInvenotry* m_playerInventory;
        std::vector<Ability *> m_abilities;
        /*Entities::Armor *m_armorSlot;
        Entities::Relic *m_relicSlot;
        Entities::Weapon *m_weaponSlot;
        std::vector<Entities::Item *> m_inventory;*/
        Map::Point* m_position;
    public:

        Player(std::string name);

        int getHealth();

        int getStrenght();

        int getArmor();

        //void equipArmor(Entities::Armor *armor);

        //void dropArmor();

        //void equipRelic(Entities::Relic *relic);

        //void dropRelic();

        //void equipWeapon(Entities::Weapon *weapon);

        //int getWeaponDamage();

        //void dropWeapon();

        std::string getName();

        void takeDamage(int damage);

        bool isAlive();

        void addAbility(Ability * ability);

        std::vector<Ability*> getAbilities();

        //void useReplenishment(Entities::Consumable *consumable);

        void setHealth(int health); //debug

        void lowerAbilityCooldown();

        //void deleteItemFromInvenotry(int itemIndex);

        std::vector<Entities::Item*> getPlayerInvenotry();

        //Entities::Armor* getEquippedArmor();

        //Entities::Weapon* getEquippedWeapon();

        //Entities::Relic* getEquippedRelic();

        //void addItem(Entities::Item * item);

        //Entities::Item* getItemFromInvenotry(int itemIndex);

        int getMaxHealth();

        Ability* getAbility(int abilityIndex);

        Map::Point* getPlayerPosition();

        void changePlayerPosition(int x, int y);

        void equipItem(int InventoryIndex);
    };
}











#endif //ZOOLS2023_XKADERK2_PLAYER_H
