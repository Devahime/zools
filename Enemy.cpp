//
// Created by xkapp on 17.04.2023.
//


#include "Enemy.h"

Entities::Enemy::Enemy(std::string name, int health, int armor, int strenght) {
    m_name = name;
    m_health = health;
    m_armor = armor;
    m_strenght = strenght;
    m_itemDrop = nullptr;
    m_abilites = {};
}

void Entities::Enemy::addItemDrop(Entities::Item *item) {
    m_itemDrop = item;
}

void Entities::Enemy::addAbility(Player::Ability *ability) {
    m_abilites.push_back(ability);
}