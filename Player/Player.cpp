//
// Created by xkapp on 16.04.2023.
//

#include "Player.h"
#include "Ability.h"
#include "Punch.h"
#include "Slash.h"
#include "Kick.h"


Player::Player::Player(std::string name) {
    m_name = name;
    m_health = 100;
    m_maxHealth = 100;
    m_armor = 0;
    m_strenght = 10;
    m_abilities = {new Punch(), new Kick()};
    m_playerInventory = new PlayerInventory();
    m_position = new Map::Point{1,3}; //debug
}

int Player::Player::getHealth() {
    return m_health;
}

int Player::Player::getStrenght() {
    return m_strenght;
}

void Player::Player::dropArmor() {
    m_armor -= m_playerInventory->getEquippedArmor()->getArmorValue();
    m_playerInventory->dropArmor();
}


void Player::Player::dropRelic() {
    m_strenght -= m_playerInventory->getEquippedRelic()->getStrenghtBonus();
    m_maxHealth -= m_playerInventory->getEquippedRelic()->getHealthBonus();
    m_playerInventory->dropRelic();
}


void Player::Player::dropWeapon() {
    m_playerInventory->dropWeapon();
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


std::vector<Player::Ability *> Player::Player::getAbilities() {
    return m_abilities;
}


void Player::Player::useReplenishment(Entities::Consumable *consumable, int itemIndex) {
    if (m_health+consumable->getReplenishemntValue()>m_maxHealth) {
        m_health = m_maxHealth;
    } else {
        m_health += consumable->getReplenishemntValue();
    }
    m_playerInventory->deleteItemFromInventory(itemIndex);
}


void Player::Player::lowerAbilityCooldown() {
    for (int i = 0; i < m_abilities.size(); ++i) {
        if(m_abilities[i]->getCooldown() != 0) {
            m_abilities[i]->lowerCooldown();
        }
    }
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


void Player::Player::equipItem(int InventoryIndex) {
    auto itemToEquip = m_playerInventory->getItemByIndex(InventoryIndex);

    if (itemToEquip->getItemType() == Entities::ItemType::weapon) {
        if (m_playerInventory->isWeaponSlotEmpty()) {
            addAbility(new Slash());
            m_playerInventory->equipWeapon(static_cast<Entities::Weapon*>(itemToEquip));
        } else {
            dropWeapon();
            addAbility(new Slash());
            m_playerInventory->equipWeapon(static_cast<Entities::Weapon*>(itemToEquip));
        }


    } else if (itemToEquip->getItemType() == Entities::ItemType::armor) {
        if (m_playerInventory->isArmorSlotEmpty()) {
            m_playerInventory->equipArmor(static_cast<Entities::Armor*>(itemToEquip));
            m_armor = static_cast<Entities::Armor*>(itemToEquip)->getArmorValue();
        } else {
            dropArmor();
            m_playerInventory->equipArmor(static_cast<Entities::Armor*>(itemToEquip));
            m_armor = static_cast<Entities::Armor*>(itemToEquip)->getArmorValue();
        }


    } else if (itemToEquip->getItemType() == Entities::ItemType::relic) {
        if (m_playerInventory->isRelicSlotEmpty()){
            m_playerInventory->equipRelic(static_cast<Entities::Relic*>(itemToEquip));
            m_strenght += static_cast<Entities::Relic*>(itemToEquip)->getStrenghtBonus();
            if (m_health == m_maxHealth) {
                m_maxHealth += static_cast<Entities::Relic*>(itemToEquip)->getHealthBonus();
                m_health = m_maxHealth;
            } else {
                m_maxHealth += static_cast<Entities::Relic*>(itemToEquip)->getHealthBonus();
            }

        } else {
            dropRelic();
            m_playerInventory->equipRelic(static_cast<Entities::Relic*>(itemToEquip));
            m_strenght += static_cast<Entities::Relic*>(itemToEquip)->getStrenghtBonus();
            if (m_health == m_maxHealth) {
                m_maxHealth += static_cast<Entities::Relic*>(itemToEquip)->getHealthBonus();
                m_health = m_maxHealth;
            } else {
                m_maxHealth += static_cast<Entities::Relic*>(itemToEquip)->getHealthBonus();
            }
        }
    }
}


Player::PlayerInventory *Player::Player::getPlayerInvenotry() {
    return m_playerInventory;
}


void Player::Player::addItemToInventory(Entities::Item *item) {
    m_playerInventory->addItem(item);
}


void Player::Player::resetAbilityCooldowns() {
    for (int i = 0; i < m_abilities.size(); ++i) {
        if(m_abilities[i]->getCooldown() != 0) {
            m_abilities[i]->resetCooldown();
        }
    }
}


Player::Player::~Player() {
    delete m_playerInventory;
    for (int ability = 0; ability < m_abilities.size(); ++ability) {
        delete m_abilities.at(ability);
    }
    delete m_position;
}