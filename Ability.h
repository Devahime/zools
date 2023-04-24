//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ABILITY_H
#define ZOOLS2023_XKADERK2_ABILITY_H

#include <string>

namespace Player {
    class Ability {
    protected:
        std::string m_name;
        std::string m_description;
        int m_cooldown;
        int m_cooldownTimer;

    public:
            Ability(std::string name, std::string description);

            virtual int doDamage(int damage, int strenght) = 0;

            std::string getName();

            std::string getDescription();



    };


}





#endif //ZOOLS2023_XKADERK2_ABILITY_H
