//
// Created by xkapp on 24.04.2023.
//

#include "Slash.h"
#include "math.h"


Player::Slash::Slash(): Ability("Slash","Let the enemy feel the sharpness of your blade") {
    m_cooldown = 0;
    m_cooldownTimer = 0;
}

int Player::Slash::doDamage(int damage, int strenght) {
    return damage + round(strenght*0.5);
}

