//
// Created by xkapp on 16.04.2023.
//

#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Relic.h"
#include "Armor.h"
#include "Ability.h"
#include "Punch.h"



Player::Player::Player(std::string name) {
    m_name = name;
    m_health = 100;
    m_maxHealth = 100;
    m_armor = 0;
    m_strenght = 10;
    m_abilities = {new ::Player::Punch("Punch", "Punch the enemy with your fists")};
    m_armorSlot = nullptr;
    m_relicSlot = nullptr;
    m_weaponSlot = nullptr;
    m_inventory = {};
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

void Player::Player::equipArmor(Entities::Armor *armor) {
    m_armorSlot = armor;
}

void Player::Player::dropArmor() {
    m_armor -= m_armorSlot->getArmorValue();
    m_armorSlot = nullptr;
}

void Player::Player::equipRelic(Entities::Relic *relic) {
    m_relicSlot = relic;
}

void Player::Player::dropRelic() {
    m_strenght -= m_relicSlot->getStrenghtBonus();
    m_maxHealth -= m_relicSlot->getHealthBonus();
    m_relicSlot = nullptr;
}

void Player::Player::equipWeapon(Entities::Weapon *weapon) {
    m_weaponSlot = weapon;
}

void Player::Player::dropWeapon() {
    m_weaponSlot = nullptr;
}

std::string Player::Player::getName() {
    return m_name;
}

void Player::Player::takeDamage(int damage) {
    int damageWithArmor = damage - m_armor;
    if (damageWithArmor<=0) {
        nullptr;
    } else {
        m_health - damageWithArmor;
    }

    if (m_health <= 0) {
        //solve how to make player dead
    }

}

bool Player::Player::isAlive() {
    if(m_health>=0) {
        return false;
    } else {
        return true;
    }
}


void Player::Player::addAbility(::Player::Ability *ability) {
    m_abilities.push_back(ability);
}


int Player::Player::getWeaponDamage() {
    if (m_weaponSlot != nullptr) {
        return m_weaponSlot->getDamage();
    }
}

    std::vector<Player::Ability *> Player::Player::getAbilities() {
    return m_abilities;
}




