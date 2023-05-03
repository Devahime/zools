//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_SLASH_H
#define ZOOLS2023_XKADERK2_SLASH_H

#include "Ability.h"

namespace Player {
    class Slash : public Ability {
        /**
         * Child class of Ability.
         * This ability is only available when Player has equipped weapon.
         * This ability has no cooldown.
         * The damage output of this ability is damage of the weapon + strenght * 0.7
         */

    public:
        Slash();

        int doDamage(int damage, int strenght) override;

    };
}

#endif //ZOOLS2023_XKADERK2_SLASH_H
