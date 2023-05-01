//
// Created by xkapp on 24.04.2023.
//

#include "Ability.h"


Player::Ability::Ability(std::string name, std::string description) {
    m_name = name;
    m_description = description;
}

std::string Player::Ability::getName() {
    return m_name;
}

std::string Player::Ability::getDescription() {
    return m_description;
}

int Player::Ability::getCooldown() {
    return m_cooldown;
}

void Player::Ability::lowerCooldown() {
    if (m_cooldown != 0) {
        if ((m_cooldownTimer-1)==-1) {

        } else {
            m_cooldownTimer -= 1;
        }
    }
}

void Player::Ability::resetCooldown() {
    m_cooldownTimer = 0;
}