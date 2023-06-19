//
// Created by xkapp on 24.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_COMBAT_H
#define ZOOLS2023_XKADERK2_COMBAT_H

#include "../Player/Player.h"
#include "../Entitites/Enemy.h"


namespace GameLogic {
    class Combat{
        /**
         * Class used for combat
         * Combat happens only in this class. Instance of this class is in Class Game.
         * Every time combat occures this class is used.
         * Parametres of this class is the player, enemy and turn information.
         * Every class that in some way needs adn uses turn information (for example ability cooldown) gets the information
         * about turn from this class
         * //todo describe procces of combat
         * Once combat is over (either Player or Monster dies) the parameters of the class are reset.
         */

        int m_turn;
        bool m_playersTurn;
        Player::Player* m_player;
        Entities::Enemy* m_enemy;

    public:
        Combat();

        void beginCombat(Player::Player* player, Entities::Enemy* enemy);

        void reset();

        void nextTurn();

        std::string checkAliveStatus();

        bool isPlayersTurn();

        void playerCombatAction(int abilityIndex);

        void enemyCombatAction();

        int enemyDamageFromAction();
    };
}

#endif //ZOOLS2023_XKADERK2_COMBAT_H
