//
// Created by xkapp on 24.04.2023.
//

#include "Punch.h"
#include <string>
#include "math.h"
#include "stdlib.h"

Player::Punch::Punch(): Ability("Punch", "Punch the soul out of your enemy") {

    m_cooldown = 0;
    m_cooldownTimer = 0;
}

int Player::Punch::doDamage(int damage, int strength) {
    return strength; //() % int ((strength + round(0.2*strength)) + (strength - round(0.2*strength)));
}