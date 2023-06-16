//
// Created by xkapp on 16.06.2023.
//

#ifndef ZOOLS2023_XKADERK2_PLAYERINVENTORY_H
#define ZOOLS2023_XKADERK2_PLAYERINVENTORY_H
#include "../Entitites/Item.h"
#include "vector"
#include "../Entitites/Item.h"
#include "../Entitites/Weapon.h"
#include "../Entitites/Relic.h"
#include "../Entitites/Armor.h"
#include "../Entitites/Consumable.h"


namespace Player {
    class PlayerInventory {
        std::vector<Entities::Item*> m_itemInventory;
        Entities::Weapon* m_weaponSlot;
        Entities::Armor* m_armorSlot;
        Entities::Relic* m_relicSlot;
    public:

        PlayerInventory();

        std::vector<Entities::Item*> getAllItems();

        void equipArmor(Entities::Armor* armor);

        void dropArmor();

        Entities::Armor* getEquippedArmor();

        void equipRelic(Entities::Relic* relic);

        void dropRelic();

        Entities::Relic* getEquippedRelic();

        void equipWeapon(Entities::Weapon* weapon);

        void dropWeapon();

        Entities::Weapon* getEquippedWeapon();

        int getWeaponDamage();

        void deleteItemFromInventory(int inventoryIndex);

        void addItem(Entities::Item* item);

        Entities::Item* getItemByIndex(int itemIndex);

        bool isArmorSlotEmpty();

        bool isWeaponSlotEmpty();

        bool isRelicSlotEmpty();
    };
}







#endif //ZOOLS2023_XKADERK2_PLAYERINVENTORY_H
