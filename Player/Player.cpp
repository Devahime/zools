//
// Created by xkapp on 16.04.2023.
//

#include "Player.h"
#include "Ability.h"
#include "Punch.h"
#include "Slash.h"



Player::Player::Player(std::string name) {
    m_name = name;
    m_health = 100;
    m_maxHealth = 100;
    m_armor = 0;
    m_strenght = 10;
    m_abilities = {new Punch()};
    m_armorSlot = nullptr;
    m_relicSlot = nullptr;
    m_weaponSlot = nullptr;
    m_inventory = {};
    m_position = new Map::Point{0,0};
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
    addAbility(new Slash());
}

void Player::Player::dropWeapon() {
    m_weaponSlot = nullptr;
    for (int i = 0; i < m_abilities.size(); ++i) {
        if (m_abilities[i]->getName() == "Slash") {
            delete m_abilities[i];
            m_abilities.erase(i + m_abilities.begin());
        }
    }
}

std::string Player::Player::getName() {
    return m_name;
}

void Player::Player::takeDamage(int damage) {
    int damageWithArmor = damage - m_armor;
    if (damageWithArmor<=0) {
        nullptr;
    } else {
        m_health = m_health - damageWithArmor;
    }

    if (m_health <= 0) {
        //solve how to make player dead
    }

}

bool Player::Player::isAlive() {
    if(m_health>0) {
        return true;
    } else {
        return false;
    }
}


void Player::Player::addAbility(::Player::Ability *ability) {
    m_abilities.push_back(ability);
}


int Player::Player::getWeaponDamage() {
    if (m_weaponSlot != nullptr) {
        return m_weaponSlot->getDamage();
    } else {
        return 0;
    }
}

std::vector<Player::Ability *> Player::Player::getAbilities() {
    return m_abilities;
}

void Player::Player::useReplenishment(Entities::Consumable *consumable) {
    if (m_health+consumable->getReplenishemntValue()>m_maxHealth) {
        m_health = m_maxHealth;
    } else {
        m_health += consumable->getReplenishemntValue();
    }
}

void Player::Player::setHealth(int health) { //debug
    m_health = health;
}

void Player::Player::lowerAbilityCooldown() {
    for (int i = 0; i < m_abilities.size(); ++i) {
        if(m_abilities[i]->getCooldown() != 0) {
            m_abilities[i]->lowerCooldown();
        }
    }

}

void Player::Player::deleteItemFromInvenotry(int itemIndex) {
    delete getItemFromInvenotry(itemIndex);
    m_inventory.erase(itemIndex+m_inventory.begin());
}

std::vector<Entities::Item *> Player::Player::getInvenotry() {
    return m_inventory;
}

Entities::Armor* Player::Player::getEquippedArmor() {
    return m_armorSlot;
}

Entities::Relic* Player::Player::getEquippedRelic() {
    return m_relicSlot;
}

Entities::Weapon* Player::Player::getEquippedWeapon() {
    return m_weaponSlot;
}

void Player::Player::addItem(Entities::Item *item) {
    m_inventory.push_back(item);
}

Entities::Item *Player::Player::getItemFromInvenotry(int itemIndex) {
    return m_inventory[itemIndex];
}

int Player::Player::getMaxHealth() {
    return m_maxHealth;
}

Player::Ability* Player::Player::getAbility(int abilityIndex) {
    return m_abilities[abilityIndex];
}

Map::Point* Player::Player::getPlayerPosition() {
    return m_position;
}

void Player::Player::changePlayerPosition(int x, int y) {
    m_position->x = x;
    m_position->y = y;
}
