//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ABILITY_H
#define ZOOLS2023_XKADERK2_ABILITY_H

#include <string>

namespace Player {
    class Ability {
        /**
         * This class is the "template" for all abilities player and enemies can use.
         * All children inherit all the atributes and all functions.
         * The constructor has name and short description which is statically declared depending on what child is calling class
         * is calling the constructor.
         * Ability can have a cooldown in which case m_cooldown determines the cooldown and m_cooldownTimer is decreasing each Turn (in class Combat),
         * till it reaches zero.
         *  Therefore Ability can only be used if the m_cooldownTimer = 0
         * Cooldown is active only in combat, if player exits combat all cooldown timers on all abilites reset to zero.
         *
         * */

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

            int getCooldown();



    };


}





#endif //ZOOLS2023_XKADERK2_ABILITY_H
