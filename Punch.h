//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_PUNCH_H
#define ZOOLS2023_XKADERK2_PUNCH_H

#include "Ability.h"
#include <string>

namespace Player {
    class Punch : public Ability {
    public:
        Punch();

        int doDamage(int damage, int strenght) override;

    };
}




#endif //ZOOLS2023_XKADERK2_PUNCH_H
