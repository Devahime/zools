//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_SLASH_H
#define ZOOLS2023_XKADERK2_SLASH_H

#include "Ability.h"

namespace Player {
    class Slash : public Ability {
    public:
        Slash();

        int doDamage(int damage, int strenght) override;

    };
}

#endif //ZOOLS2023_XKADERK2_SLASH_H
