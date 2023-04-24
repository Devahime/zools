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
        Punch(std::string description);

        int doDamage(int damage, int strenght);

    };
}




#endif //ZOOLS2023_XKADERK2_PUNCH_H
