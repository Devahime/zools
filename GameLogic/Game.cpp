//
// Created by xkapp on 29.04.2023.
//

#include "Game.h"
#include <iostream>
#include <stdlib.h>
//#define ASCII_ESC 27
#include "../Entitites/ItemType.h"
#include <chrono>
#include <thread>
#include <conio.h>
#include "../Map/Floor.h"
#include "../Map/Wall.h"
#include "../Map/PlayerTile.h"
#include "../Map/Door.h"
#include "../Map/EnemyTile.h"
#include "../Map/ItemTile.h"
#include "../Player/Kick.h"


GameLogic::Game::Game(Player::Player *player, Map::Level* level) {
    m_player = player;
    m_combat = nullptr;
    m_currentMap = 0;
    m_level = level;
    m_gui = new GUI();
    m_gameComplete = false;
    m_killedEnemies = 0;
    m_pickedItems = 0;
    m_potionsUsed = 0;
}


bool GameLogic::Game::checkForAction(char input) {
    //Checking pressedkey (input), then doing action acording to controls
    if (m_gameComplete) {
        return false;
    }

    if (input == 'w') {
        mapMovement(input);
        if (m_gameComplete) {
            return false;
        }
        printGameScreen();
        return true;

    } else if(input == 'a') {
        mapMovement(input);
        if (m_gameComplete) {
            return false;
        }
        printGameScreen();
        return true;

    } else if(input == 's') {
        mapMovement(input);
        if (m_gameComplete) {
            return false;
        }
        printGameScreen();
        return true;

    } else if(input == 'd') {
        mapMovement(input);
        if (m_gameComplete) {
            return false;
        }
        printGameScreen();
        return true;

    } else if(input == 'x') {
        //exits the game
        return false;

    } else if(input == 'i') {
        //opens invetory
        InventoryGUI();
        printGameScreen();
        return true;

    } else {
        //if the keypressed is not found in this if tree, map is refreshed
        printGameScreen();
    }
}


void GameLogic::Game::clearScreen() {
    m_gui->clearScreen();
}


void GameLogic::Game::InventoryGUI() {
    auto PlayerInventory = m_player->getPlayerInvenotry();
    auto inventory = PlayerInventory->getAllItems();
    m_gui->printInventory(inventory, m_player);

    std::string input;
    std::cin >> input;

    //if players types q, inventoryGUI will finish and the player will be brought back to gamescreen/combat
    if (input=="q") {
        //continue without action -> quit
    } else if (std::stoi(input) >=1 and std::stoi(input) <= inventory.size()+1) {
        clearScreen();
       // Entities::Item* pickedItem = inventory[input]; nefunguje
       int pickedItemIndex = std::stoi(input) -1;

        if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::armor) {
            if (inventory[pickedItemIndex] == PlayerInventory->getEquippedArmor()) {
                m_gui->printArmorInfo(static_cast<Entities::Armor*>(inventory[pickedItemIndex]), true);
            } else {
                m_gui->printArmorInfo(static_cast<Entities::Armor*>(inventory[pickedItemIndex]), false);
            }


        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::relic) {
            if (inventory[pickedItemIndex] == PlayerInventory->getEquippedRelic()) {
                m_gui->printRelicInfo(static_cast<Entities::Relic*>(inventory[pickedItemIndex]), true);
            } else {
                m_gui->printRelicInfo(static_cast<Entities::Relic*>(inventory[pickedItemIndex]), false);
            }


        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::weapon) {
            if (inventory[pickedItemIndex] == PlayerInventory->getEquippedWeapon()) {
                m_gui->printWeaponInfo(static_cast<Entities::Weapon*>(inventory[pickedItemIndex]), true);
            } else {
                m_gui->printWeaponInfo(static_cast<Entities::Weapon*>(inventory[pickedItemIndex]), false);
            }


        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::consumable) {
            m_gui->printConsumableInfo(static_cast<Entities::Consumable*>(inventory[pickedItemIndex]));
        }

        //player can "use" the item whci means equip/unequip or consume (consumable)
        std::cout << "\nEnter 'u' to use or equip item or any other letter to exit: ";
        std::cin >> input;

        if (input == "u") {

            if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::consumable) {
                m_player->useReplenishment(static_cast<Entities::Consumable*>(inventory[pickedItemIndex]), pickedItemIndex);
                m_potionsUsed+= 1;
            } else {
                if (inventory[pickedItemIndex] == PlayerInventory->getEquippedWeapon()) {
                    m_player->dropWeapon();
                } else if (inventory[pickedItemIndex] == PlayerInventory->getEquippedRelic()) {
                    m_player->dropRelic();
                } else if (inventory[pickedItemIndex] == PlayerInventory->getEquippedArmor()) {
                    m_player->dropArmor();
                } else {
                    m_player->equipItem(pickedItemIndex);
                }
            }
        }
    }
    //after this the screen will be cleared so next event ifnromation can be shown
    clearScreen();
}


bool GameLogic::Game::combat(Entities::Enemy* enemy) {
    bool combat = true;
    m_combat = new Combat();
    m_combat->beginCombat(m_player,enemy); //debug

    while (combat) {
        combatGUI(enemy);

        if (m_combat->checkAliveStatus() != "bothAlive") {
            combat = false;
        }

        clearScreen();
    }

    if (m_combat->checkAliveStatus() == "playerDead") {
        delete m_combat;
        m_combat = nullptr;
        return false;

    } else if (m_combat->checkAliveStatus() == "enemyDead") {
        delete m_combat;
        m_combat = nullptr;
        m_player->resetAbilityCooldowns();
        m_killedEnemies +=1;
        return true;
    }
}


void GameLogic::Game::combatGUI(Entities::Enemy *enemy) {
    std::string choice;

    //checking if player has turn, if so, player can then cast ability or check inventory
    if (m_combat->isPlayersTurn()) {
        m_gui->combatScreen(m_player, enemy, true);
        std::cin >> choice;

        if (choice=="i") {
            InventoryGUI();
            //if player chooses inventory, he still has turn, and once the combat gui will be called again, he can cast ability (or enter
            //inventory again)
        } else if (std::stoi(choice) > 0 and std::stoi(choice) <= m_player->getAbilities().size()) {
            m_combat->playerCombatAction(std::stoi(choice)-1);
            //if player chose ability, then enemy has the turn
        }

    } else {
        //enemy turn
        m_gui->combatScreen(m_player, enemy, false);
        m_combat->enemyCombatAction();
    }

}


void GameLogic::Game::printTutorial() {
    std::string input;

    m_gui->printTutorial(m_player);
    input = _getch();
    clearScreen();

}


bool GameLogic::Game::isPlayerAlive() {
    return m_player->isAlive();
}


void GameLogic::Game::printGameScreen() {
    m_gui->printGameScreen(m_player,m_level->getMap(m_currentMap),m_currentMap);
}


void GameLogic::Game::mapMovement(char pressedKey) {

    Map::Point *cordinates = m_player->getPlayerPosition();
    auto map = m_level->getMap(m_currentMap);

    int xCordinate = cordinates->x;
    int yCordinate = cordinates->y;

    int xNewCordiante;
    int yNewCordinate;

    if (pressedKey == 'w') {
        xNewCordiante = xCordinate;
        yNewCordinate = yCordinate - 1;

    } else if (pressedKey == 'a') {
        xNewCordiante = xCordinate - 1;
        yNewCordinate = yCordinate;

    } else if (pressedKey == 's') {
        xNewCordiante = xCordinate;
        yNewCordinate = yCordinate + 1;

    } else if (pressedKey == 'd') {
        xNewCordiante = xCordinate + 1;
        yNewCordinate = yCordinate;
    }

    if (map->isNotWall(xNewCordiante, yNewCordinate)) {
        //check if target tile is door
        if (map->isDoor(xNewCordiante, yNewCordinate)) {
            //cehck if the door is exit or entry one
            if (static_cast<Map::Door *>(map->getTile(xNewCordiante, yNewCordinate))->isExitDoor()) {
                m_currentMap = static_cast<Map::Door *>(map->getTile(xNewCordiante, yNewCordinate))->getTargetRoom();
                if (m_currentMap+1>m_level->getLevelSize()) {
                    completeTheGame();
                } else {
                    newMapSetup(true);
                }
            } else {
                m_currentMap = static_cast<Map::Door *>(map->getTile(xNewCordiante, yNewCordinate))->getTargetRoom();
                newMapSetup(false);
            }

        } else if (map->isEnemy(xNewCordiante, yNewCordinate)) {
            Entities::Enemy *enemy = static_cast<Map::EnemyTile *>(map->getTile(xNewCordiante,
                                                                                yNewCordinate))->getEnemy();
            bool combatResult = combat(enemy);
            if (combatResult) {
                auto item = enemy->dropItem();

                if (item != nullptr) {
                    map->replaceTile(xNewCordiante, yNewCordinate, new Map::ItemTile(item));
                } else {
                    map->replaceTile(xNewCordiante, yNewCordinate, new Map::Floor());
                }
            }


        } else if (map->isItem(xNewCordiante, yNewCordinate)) {
            auto item = static_cast<Map::ItemTile *>(map->getTile(xNewCordiante, yNewCordinate))->takeItem();
            m_player->addItemToInventory(item);
            map->swapTiles(xCordinate, yCordinate, xNewCordiante, yNewCordinate);
            m_player->changePlayerPosition(xNewCordiante, yNewCordinate);
            //already swapped tile, need to go back cordinate wise
            map->replaceTile(xCordinate, yCordinate, new Map::Floor());
            m_pickedItems += 1;


        } else {
            map->swapTiles(xCordinate, yCordinate, xNewCordiante, yNewCordinate);
            m_player->changePlayerPosition(xNewCordiante, yNewCordinate);
        }
    }
}



void GameLogic::Game::newMapSetup(bool isExitDoor) {
    auto map = m_level->getMap(m_currentMap);

    if (isExitDoor) {
        auto point = map->getEntryPoint();
        m_player->changePlayerPosition(point->x, point->y);
        map->replaceTile(point->x, point->y, new Map::PlayerTile());

    } else {
        auto point = map->getExitPoint();
        m_player->changePlayerPosition(point->x, point->y);
        map->replaceTile(point->x, point->y, new Map::PlayerTile());
    }

}


bool GameLogic::Game::isGameCompleted() {
    return m_gameComplete;
}


void GameLogic::Game::completeTheGame() {
    char input;
    m_gui->gameCompletionScreen(m_player->getName(),m_killedEnemies, m_pickedItems, m_potionsUsed);
    m_gameComplete = true;
    input = _getch();
}

GameLogic::Game::~Game() {
    delete m_player;
    delete m_level;
    delete m_gui;
}
