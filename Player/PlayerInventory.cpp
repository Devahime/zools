//
// Created by xkapp on 16.06.2023.
//

#include "PlayerInventory.h"

Player::PlayerInvenotry::PlayerInvenotry() {
    m_itemInventory = {};
    m_weaponSlot = nullptr;
    m_relicSlot = nullptr;
    m_armorSlot = nullptr;
}

std::vector<Entities::Item *> Player::PlayerInvenotry::getAllItems() {
    return m_itemInventory;
}

void Player::PlayerInvenotry::equipArmor(Entities::Armor *armor) {
    m_armorSlot = armor;
}

void Player::PlayerInvenotry::dropArmor() {
    m_armorSlot = nullptr;
}

Entities::Armor* Player::PlayerInvenotry::getEquippedArmor() {
    return m_armorSlot;
}

void Player::PlayerInvenotry::equipRelic(Entities::Relic * relic) {
    m_relicSlot = relic;
}

void Player::PlayerInvenotry::dropRelic() {
    m_relicSlot = nullptr;
}

Entities::Relic *Player::PlayerInvenotry::getEquippedRelic() {
    return m_relicSlot;
}

void Player::PlayerInvenotry::equipWeapon(Entities::Weapon *weapon) {
    m_weaponSlot = weapon;
}

void Player::PlayerInvenotry::dropWeapon() {
    m_weaponSlot = nullptr;
}

Entities::Weapon *Player::PlayerInvenotry::getEquippedWeapon() {
    return m_weaponSlot;
}

int Player::PlayerInvenotry::getWeaponDamage() {
    if (m_weaponSlot != nullptr) {
        return m_weaponSlot->getDamage();
    } else {
        return 0;
    }
}

Entities::Item *Player::PlayerInvenotry::getItemByIndex(int itemIndex) {
    return m_itemInventory.at(itemIndex);
}

void Player::PlayerInvenotry::deleteItemFromInventory(int inventoryIndex) {
    delete getItemByIndex(inventoryIndex);
    m_itemInventory.erase(inventoryIndex+m_itemInventory.begin());
}

void Player::PlayerInvenotry::addItem(Entities::Item *item) {
    m_itemInventory.push_back(item);
}

bool Player::PlayerInvenotry::isArmorSlotEmpty() {
    if (m_armorSlot == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool Player::PlayerInvenotry::isRelicSlotEmpty() {
    if (m_relicSlot == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool Player::PlayerInvenotry::isWeaponSlotEmpty() {
    if (m_weaponSlot == nullptr) {
        return true;
    } else {
        return false;
    }
}