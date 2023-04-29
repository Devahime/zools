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

