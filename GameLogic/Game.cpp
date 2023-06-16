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


GameLogic::Game::Game(Player::Player *player, Map::Level* level) {
    m_player = player;
    m_combat = nullptr;
    m_currentMap = 0;
    m_level = level;
    m_gui = new GUI();
}

bool GameLogic::Game::checkForAction(char input) {
    //Could be done by case switch
    //Checking pressedkey (input), then doing action acording to controls
    if (input == 'w') {
        //std::cout << "Nahoru" << std::endl;
        mapMovement(input);
        printGameScreen();
        return true;

    } else if(input == 'a') {
        mapMovement(input);
        printGameScreen();
        return true;

    } else if(input == 's') {
        //std::cout << "Dolu" << std::endl;
        mapMovement(input);
        printGameScreen();
        return true;

    } else if(input == 'd') {
        mapMovement(input);
        //std::cout << "Doprava" << std::endl;
        printGameScreen();
        return true;

    } else if(input == 'x') {
        //exits the game
        //std::cout << "Exit" << std::endl;
        return false;

    } else if(input == 'i') {
        //opens invetory
        InventoryGUI();
        printGameScreen();
        return true;

    } else if (input == 'e') { //debug
        auto abilitites = m_player->getAbilities();
        for (int i = 0; i < abilitites.size(); ++i) {
            std::cout << abilitites[i]->getName() << std::endl;
        }
        return true;

    } /*else if (input == 'c') { //debug
        if (combat()){
            return true;
        } else {
            return false;
        }

    }*/ else {
        //if the keypressed is not found in this if tree, map is refreshed
        printGameScreen();
    }
}


void GameLogic::Game::printMap() {
    Map::Map* map = m_level->getMap(m_currentMap);
    map->print();
}

void GameLogic::Game::clearScreen() {
    m_gui->clearScreen();
}

void GameLogic::Game::printPlayer() { //debug
    std::cout << m_player->getName();
}



bool GameLogic::Game::combat(Entities::Enemy* enemy) {
    bool combat = true;
    //auto enemy = new Entities::Enemy("skeleton", 80, 10, 5); //debug
    m_combat = new Combat();
    m_combat->beginCombat(m_player,enemy); //debug

    while (combat) {
        combatGUI(enemy);

        if (m_combat->checkAliveStatus() != "bothAlive") {
            combat = false;
        }
        /*if (m_combat->isPlayersTurn()) {

        } else {
            m_combat->nextTurn();
        }*/
        clearScreen();
    }


    if (m_combat->checkAliveStatus() == "playerDead") {
        delete m_combat;
        m_combat = nullptr;
        return false;

    } else if (m_combat->checkAliveStatus() == "enemyDead") {
        delete m_combat;
        m_combat = nullptr;
        return true;
    }
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
            } else {
                m_player->equipItem(pickedItemIndex);
            }
            /*if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::consumable) {
               m_player->useReplenishment(static_cast<Entities::Consumable*>(inventory[pickedItemIndex]));
               m_player->deleteItemFromInvenotry(pickedItemIndex);


            } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::weapon) {
                if (inventory[pickedItemIndex] == m_player->getEquippedWeapon()) {
                    m_player->dropWeapon();
                } else {
                    m_player->dropWeapon();
                    m_player->equipWeapon(static_cast<Entities::Weapon*>(inventory[pickedItemIndex]));
                }


            } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::armor){
                if (inventory[pickedItemIndex] == m_player->getEquippedArmor()) {
                    m_player->dropArmor();
                } else {
                    m_player->dropArmor();
                    m_player->equipWeapon(static_cast<Entities::Weapon*>(inventory[pickedItemIndex]));
                }


            } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::relic) {
                if (inventory[pickedItemIndex] == m_player->getEquippedRelic()) {
                    m_player->dropRelic();
                } else {
                    m_player->dropRelic();
                    m_player->equipRelic(static_cast<Entities::Relic*>(inventory[pickedItemIndex]));
                }
            }*/

        }


    }

    //after this the screen will be cleared so next event ifnromation can be shown
    clearScreen();

}




void GameLogic::Game::combatGUI(Entities::Enemy *enemy) {

    std::string choice;
    //overview of combat participants
    std::cout << "          |--------Combat--------|\n" << std::endl;
    std::cout << "   Enemy: " << enemy->getName() << " [" << enemy->getHealth() << "/" << enemy->getMaxHealth() << "]\n\n\n" << std::endl;
    std::cout << "   You:   " << m_player->getName() << " [" << m_player->getHealth() << "/" << m_player->getMaxHealth() << "]\n" << std::endl;

    //checking if player has turn, if so, player can then cast ability or check inventory
    if (m_combat->isPlayersTurn()) {
        std::cout << "          Your turn" << std::endl;
        printAbilityOverview();
        std::cout << "'i' Inventory\n" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice=="i") {
            InventoryGUI();
            //if player chooses inventory, he still has turn, and once the combat gui will be called again, he can cast ability (or enter
            //inventory again)
        } else if (std::stoi(choice) > 0 and std::stoi(choice) <= m_player->getAbilities().size()) {
            auto ability = m_player->getAbility(std::stoi(choice)-1);
            if (ability->getName()!="Slash") {
                enemy->takeDamage(ability->doDamage(0,m_player->getStrenght()));
            } else {
//                enemy->takeDamage(ability->doDamage(m_player->getWeaponDamage(),m_player->getStrenght()));
            }
            //if player chose ability, then enemy has the turn
            m_combat->nextTurn();

        }

    } else {
        //enemy turn
        std::cout << "          Enemy turn" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        m_player->takeDamage(m_combat->enemyDamageFromAction());

        std::cout << "\n          Enemy used Punch!" << std::endl; //debug
        std::this_thread::sleep_for(std::chrono::seconds(1));

        //once enemy finished casting his ability, player again will have turn in next function calling
        m_combat->nextTurn();
    }




}

void GameLogic::Game::printAbilityOverview() {
    //function used in combat, to display all abilities player can cast
    auto abilities = m_player->getAbilities();
         std::cout << "Abilities:" << std::endl;
    for (int i = 0; i < abilities.size(); ++i) {
        std::cout << i+1 << ". " << abilities[i]->getName() << "  ";
    }
}


//todo need to show values for item
/*void GameLogic::Game::printItemDetails(std::string type, Entities::Item *item) {
    //detail list of information of selected item
    if (item->getItemType() != Entities::ItemType::consumable) {
        std::cout << "Item name:        " << item->getName() << std::endl;
        std::cout << "Item description: " << item->getInfo() << std::endl;
        std::cout << "Item type:        " << type << std::endl;
        if (item == m_player->getEquippedArmor() or item ==  m_player->getEquippedRelic() or item ==  m_player->getEquippedWeapon()) {
            //this condition is not ideal, but because this fucntion accepts all four items, i need to check it like this.
            std::cout << "Item status:      Equipped" << std::endl;
        } else {
            std::cout << "Item status:    -    \n" << std::endl;
        }

    } else {
        std::cout << "Item name:        " << item->getName() << std::endl;
        std::cout << "Item description: " << item->getInfo() << std::endl;
        std::cout << "Item type:        consumable" << std::endl;
        std::cout << "Heal value:       " << static_cast<Entities::Consumable*>(item)->getReplenishemntValue() << "\n" << std::endl;

    }

}*/



void GameLogic::Game::printTutorial() {

    std::string input;
    std::cout << "|---------Tutorial and controls---------|\n" << std::endl;
    std::cout << "Welcome to the game "<< m_player->getName() << "!" << std::endl;
    std::cout << "In this game your task is to make it through the dungeon!" << std::endl;
    std::cout << "Be careful as there will be many thigs that will try to stop you!" << std::endl;
    std::cout << "Press any key to continue" << std::endl; //change to getch
    input = _getch();
    clearScreen();

    std::cout << "|---------Tutorial and controls---------|\n" << std::endl;
    std::cout << "    Map looks like this: " << std::endl;
    std::cout
    << "        ###############" << std::endl
    << "        #         E   #" << std::endl
    << "        # P           D" << std::endl
    << "        #           I #" << std::endl
    << "        ###############\n" << std::endl;

    std::cout << "        Map symbols legend:" << std::endl
    << "     # - Wall" << std::endl
    << "     D - Door to next room" << std::endl
    << "     E - Enemy" << std::endl
    << "     I - Item" << std::endl
    << "     P - Player (you)" << std::endl
    << "     Free space - Floor\n\n" << std::endl;

    std::cout << "        Controls:" << std::endl
    << "     w,a,s,d - Movement" << std::endl
    << "     x - Exit game" << std::endl
    << "     i - Inventory\n" << std::endl;

    std::cout << "Press any key to continue " << std::endl; //change to getch
    input = _getch();
    clearScreen();

}

bool GameLogic::Game::isPlayerAlive() {
    return m_player->isAlive();
}


void GameLogic::Game::printGameScreen() {
    std::cout << "\n" << "      Room " << m_currentMap+1 << std::endl;
    std::cout << "\n";

    printMap();
    std::cout << "\n";

    std::cout << "    Player: " << m_player->getName() <<
    "  [" << m_player->getHealth() << "/" << m_player->getMaxHealth() << "]\n" <<std::endl;

    std::cout << "        Controls:" << std::endl
              << "     w,a,s,d - Movement" << std::endl
              << "     x - Exit game" << std::endl
              << "     i - Inventory\n" << std::endl;
}




//map movement fucntions

bool isNotWall(int x, int y, Map::Map* map){
    if (map->getTile(x,y)->getType() != Map::TileType::WallType) {
        return true;
    } else {
        return false;
    }
};

bool isDoor(int x, int y, Map::Map* map){
    if (map->getTile(x,y)->getType() == Map::TileType::DoorType) {
        return true;
    } else {
        return false;
    }
}

bool isEnemy(int x, int y, Map::Map* map) {
    if (map->getTile(x, y)->getType() == Map::TileType::EnemyTileType) {
        return true;
    } else {
        return false;
    }
}

bool isItem(int x, int y, Map::Map* map) {
    if (map->getTile(x, y)->getType() == Map::TileType::Item) {
        return true;
    } else {
        return false;
    }
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


    if (isNotWall(xNewCordiante, yNewCordinate, map)) {
        //check if target tile is door
        if (isDoor(xNewCordiante, yNewCordinate, map)) {
            //cehck if the door is exit or entry one
            if (static_cast<Map::Door *>(map->getTile(xNewCordiante, yNewCordinate))->isExitDoor()) {
                m_currentMap = static_cast<Map::Door *>(map->getTile(xNewCordiante, yNewCordinate))->getTargetRoom();
                newMapSetup(true);
            } else {
                m_currentMap = static_cast<Map::Door *>(map->getTile(xNewCordiante, yNewCordinate))->getTargetRoom();
                newMapSetup(false);
            }

        } else if (isEnemy(xNewCordiante, yNewCordinate, map)) {
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


        } else if (isItem(xNewCordiante, yNewCordinate, map)) {
            auto item = static_cast<Map::ItemTile *>(map->getTile(xNewCordiante, yNewCordinate))->takeItem();
            //m_player->addItem(item);
            map->swapTiles(xCordinate, yCordinate, xNewCordiante, yNewCordinate);
            m_player->changePlayerPosition(xNewCordiante, yNewCordinate);
            //already swapped tile, need to go back cordinate wise
            map->replaceTile(xCordinate, yCordinate, new Map::Floor());


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