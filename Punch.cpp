//
// Created by xkapp on 24.04.2023.
//

#include "Punch.h"
#include <string>

Player::Punch::Punch(std::string description): Ability("Punch", description) {

    m_cooldown = 0;
    m_cooldownTimer = 0;
    m_type = "Punch";
}

int Player::Punch::doDamage(int damage, int strenght) {
    return strenght;
}