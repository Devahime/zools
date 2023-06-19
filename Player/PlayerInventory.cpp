//
// Created by xkapp on 16.06.2023.
//

#include "PlayerInventory.h"

Player::PlayerInventory::PlayerInventory() {
    m_itemInventory = {};
    m_weaponSlot = nullptr;
    m_relicSlot = nullptr;
    m_armorSlot = nullptr;
}

std::vector<Entities::Item *> Player::PlayerInventory::getAllItems() {
    return m_itemInventory;
}

void Player::PlayerInventory::equipArmor(Entities::Armor *armor) {
    m_armorSlot = armor;
}

void Player::PlayerInventory::dropArmor() {
    m_armorSlot = nullptr;
}

Entities::Armor* Player::PlayerInventory::getEquippedArmor() {
    return m_armorSlot;
}

void Player::PlayerInventory::equipRelic(Entities::Relic * relic) {
    m_relicSlot = relic;
}

void Player::PlayerInventory::dropRelic() {
    m_relicSlot = nullptr;
}

Entities::Relic *Player::PlayerInventory::getEquippedRelic() {
    return m_relicSlot;
}

void Player::PlayerInventory::equipWeapon(Entities::Weapon *weapon) {
    m_weaponSlot = weapon;
}

void Player::PlayerInventory::dropWeapon() {
    m_weaponSlot = nullptr;
}

Entities::Weapon *Player::PlayerInventory::getEquippedWeapon() {
    return m_weaponSlot;
}

int Player::PlayerInventory::getWeaponDamage() {
    if (m_weaponSlot != nullptr) {
        return m_weaponSlot->getDamage();
    } else {
        return 0;
    }
}

Entities::Item *Player::PlayerInventory::getItemByIndex(int itemIndex) {
    return m_itemInventory.at(itemIndex);
}

void Player::PlayerInventory::deleteItemFromInventory(int inventoryIndex) {
    delete getItemByIndex(inventoryIndex);
    m_itemInventory.erase(inventoryIndex+m_itemInventory.begin());
}

void Player::PlayerInventory::addItem(Entities::Item *item) {
    m_itemInventory.push_back(item);
}

bool Player::PlayerInventory::isArmorSlotEmpty() {
    if (m_armorSlot == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool Player::PlayerInventory::isRelicSlotEmpty() {
    if (m_relicSlot == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool Player::PlayerInventory::isWeaponSlotEmpty() {
    if (m_weaponSlot == nullptr) {
        return true;
    } else {
        return false;
    }
}

Player::PlayerInventory::~PlayerInventory() {
    m_weaponSlot == nullptr;
    m_relicSlot == nullptr;
    m_armorSlot == nullptr;
    for (int item = 0; item < m_itemInventory.size(); ++item) {
        delete m_itemInventory.at(item);
    }
}