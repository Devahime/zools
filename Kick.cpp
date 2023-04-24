//
// Created by xkapp on 24.04.2023.
//

#include "Kick.h"
#include "math.h"

Player::Kick::Kick(): Ability("Kick", "Hit hard with your leg") {
    m_cooldown = 1;
    m_cooldownTimer = 0;
}

int Player::Kick::doDamage(int damage, int strenght) {
    return int(round(strenght*1.2));
}
