//
// Created by xkapp on 17.04.2023.
//


#include "Enemy.h"
#include "../Player/Punch.h"

Entities::Enemy::Enemy(std::string name, int health, int armor, int strenght) {
    m_name = name;
    m_maxHealth = health;
    m_health = m_maxHealth;
    m_armor = armor;
    m_strenght = strenght;
    m_itemDrop = nullptr;
    m_abilites = {new Player::Punch()};
}

void Entities::Enemy::addItemDrop(Entities::Item *item) {
    m_itemDrop = item;
}

void Entities::Enemy::addAbility(Player::Ability *ability) {
    m_abilites.push_back(ability);
}

int Entities::Enemy::getMaxHealth() {
    return m_maxHealth;
}

std::string Entities::Enemy::getName() {
    return m_name;
}

void Entities::Enemy::takeDamage(int damage) {
    m_health -= damage;
}

std::vector<Player::Ability *> Entities::Enemy::getAbilities() {
    return m_abilites;
}

bool Entities::Enemy::isAlive() {
    if (m_health>0) {
        return true;
    } else {
        return false;
    }
}

int Entities::Enemy::getStrenght() {
    return m_strenght;
}

int Entities::Enemy::getHealth() {
    return m_health;
}