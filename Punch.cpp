//
// Created by xkapp on 24.04.2023.
//

#include "Punch.h"
#include <string>

Player::Punch::Punch(): Ability("Punch", "Punch the sould out of your enemy") {

    m_cooldown = 0;
    m_cooldownTimer = 0;
}

int Player::Punch::doDamage(int damage, int strenght) {
    return strenght;
}