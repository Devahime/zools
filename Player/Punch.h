//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_PUNCH_H
#define ZOOLS2023_XKADERK2_PUNCH_H

#include "Ability.h"
#include <string>

namespace Player {
    class Punch : public Ability {
        /**
         * Child class of Ability.
         * Basic ability which player gets at the beggining od the game.
         * Thos ability has noo cooldown.
         * The damage output of this ability is the strenght of the user.
         */

    public:
        Punch();

        int doDamage(int damage, int strength) override;

    };
}




#endif //ZOOLS2023_XKADERK2_PUNCH_H
