//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_KICK_H
#define ZOOLS2023_XKADERK2_KICK_H

#include "Ability.h"
#include <string>


namespace Player {
    class Kick : public Ability {
    public:
        Kick();

        int doDamage(int damage, int strenght) override;
    };


}


#endif //ZOOLS2023_XKADERK2_KICK_H
