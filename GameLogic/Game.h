//
// Created by xkapp on 29.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_GAME_H
#define ZOOLS2023_XKADERK2_GAME_H


#include "../Map/Level.h"
#include "../Player/Player.h"
#include "Combat.h"
#include "../Entitites/Item.h"
#include "GUI.h"


namespace GameLogic {
    class Game {
        Map::Level* m_level;
        Player::Player* m_player;
        int m_currentMap;
        GameLogic::Combat* m_combat;
        GameLogic::GUI* m_gui;
        bool m_gameComplete;
        int m_killedEnemies;
        int m_pickedItems;
        int m_potionsUsed;

    public:
        Game(Player::Player* player, Map::Level* level);

        ~Game();

        bool checkForAction(char input);

        void InventoryGUI();

        void combatGUI(Entities::Enemy* enemy);

        bool combat(Entities::Enemy* enemy);

        void printTutorial();

        bool isPlayerAlive();

        void mapMovement(char pressedKey);

        void newMapSetup(bool isExitDoor);

        bool isGameCompleted();

        void clearScreen();

        void printGameScreen();
    private: //second private section

        void completeTheGame();
    };
}





#endif //ZOOLS2023_XKADERK2_GAME_H
