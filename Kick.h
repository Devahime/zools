//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_KICK_H
#define ZOOLS2023_XKADERK2_KICK_H

#include "Ability.h"
#include <string>


namespace Player {
    class Kick : public Ability {
        /**
         * Child class of Ability.
         * Basic ability which player gets at the beggining od the game.
         * This ability has 1 turn cooldown
         * The damage output of this ability is the strenght of the user * 1.2 .
         */
    public:
        Kick();

        int doDamage(int damage, int strenght) override;
    };


}


#endif //ZOOLS2023_XKADERK2_KICK_H
