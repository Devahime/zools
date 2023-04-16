//
// Created by xkapp on 16.04.2023.
//

#include "Player.h"



Player::Player::Player(std::string name) {
    m_name = name;
    m_health = 100;
    m_maxHealth = 100;
    m_armor = 0;
    m_strenght = 10;
    m_abilities = {};
    m_armorSlot = nullptr;
    m_relicSlot = nullptr;
    m_weaponSlot = nullptr;
}

int Player::Player::getHealth() {
    return m_health;
}

int Player::Player::getArmor() {
    return m_armor;
}

int Player::Player::getStrenght() {
    return m_strenght;
}

void Player::Player::equipArmor(Armor *armor) {
    m_armorSlot = armor;
}

void Player::Player::dropArmor() {
    m_armor -= m_armorSlot->getArmorBonus;
    m_armorSlot = nullptr;
}

void Player::Player::equipRelic(Relic *relic) {
    m_relicSlot = relic;
}

void Player::Player::dropRelic() {
    m_strenght -= m_relicSlot->getStrenghtBonus;
    m_maxHealth -= m_relicSlot->getHealthBonus;
}
