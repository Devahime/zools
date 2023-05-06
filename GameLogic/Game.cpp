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

GameLogic::Game::Game(Player::Player *player, GameLogic::Combat *combat) {
    m_player = player;
    m_combat = combat;
    m_currentMap = 0;
}

bool GameLogic::Game::checkForAction(char input) {
    //first version, to by rewrited later
    if (input == 'w') {
        //std::cout << "Nahoru" << std::endl;
        printGameScreen();
        return true;
    } else if(input == 'a') {
        //std::cout << "Doleva" << std::endl;
        printGameScreen();
        return true;
    } else if(input == 's') {
        //std::cout << "Dolu" << std::endl;
        printGameScreen();
        return true;
    } else if(input == 'd') {
        //std::cout << "Doprava" << std::endl;
        printGameScreen();
        return true;
    } else if(input == 'x') {
        //std::cout << "Exit" << std::endl;
        return false;
    } else if(input == 'i') {  //debug
        InventoryGUI();
        return true;
    } else if (input == 'e') { //debug
        auto abilitites = m_player->getAbilities();
        for (int i = 0; i < abilitites.size(); ++i) {
            std::cout << abilitites[i]->getName() << std::endl;
        }
        return true;
    } else if (input == 'c') {
        if (combat()){
            return true;
        } else {
            return false;
        }

    }
}


void GameLogic::Game::printMap(int mapNumber) {
    std::cout << "##########D##########" << std::endl; //debug
    std::cout << "#                   #" << std::endl;
    std::cout << "#    P              #" << std::endl;
    std::cout << "#                I  D" << std::endl;
    std::cout << "#                   #" << std::endl;
    std::cout << "#          E        #" << std::endl;
    std::cout << "#####################" << std::endl;
    //debug

}

void GameLogic::Game::clearScreen() {
    system("cls"); //debug
}

void GameLogic::Game::printPlayer() { //debug
    std::cout << m_player->getName();
}



bool GameLogic::Game::combat() {
    bool combat = true;
    auto enemy = new Entities::Enemy("skeleton", 80, 10, 5); //debug
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
        return false;

    } else if (m_combat->checkAliveStatus() == "enemyDead") {
        return true;
    }

}



void GameLogic::Game::InventoryGUI() {
    clearScreen();
    std::vector<Entities::Item*> inventory = m_player->getInvenotry();
    std::cout << "|-------------Inventory------------|\n" << std::endl;
    std::cout << "Item number    Item name" << std::endl;

    for (int i = 0; i < inventory.size(); ++i) {
        std::cout <<"          " << i+1 << "    " << inventory[i]->getName() << std::endl;
    }

    std::string input;
    std::cout << "\nEnter item number to make item action or 'q' to exit: ";
    std::cin >> input;


    if (input=="q") {
        //continue without action -> quit
    } else if (std::stoi(input) >=1 and std::stoi(input) <= inventory.size()+1) {
        clearScreen();
       // Entities::Item* pickedItem = inventory[input]; nefunguje
       int pickedItemIndex = std::stoi(input) -1;

        if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::armor) {
            printItemDetails("armor", inventory[pickedItemIndex]);

        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::relic) {
            printItemDetails("relic", inventory[pickedItemIndex]);

        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::weapon) {
            printItemDetails("weapon", inventory[pickedItemIndex]);

        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::consumable) {
            printItemDetails("consumable", inventory[pickedItemIndex]);
        }

        std::cout << "Enter 'u' to use or equip item or any other letter to exit: ";
        std::cin >> input;


        if (input == "u") {
            if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::consumable) {
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
            }

        }


    }

    clearScreen();


}




void GameLogic::Game::combatGUI(Entities::Enemy *enemy) {
    std::string choice;

    std::cout << "          |--------Combat--------|\n" << std::endl;
    std::cout << "   Enemy: " << enemy->getName() << " [" << enemy->getHealth() << "/" << enemy->getMaxHealth() << "]\n\n\n" << std::endl;
    std::cout << "   You:   " << m_player->getName() << " [" << m_player->getHealth() << "/" << m_player->getMaxHealth() << "]\n" << std::endl;


    if (m_combat->isPlayersTurn()) {
        std::cout << "          Your turn" << std::endl;
        printAbilityOverview();
        std::cout << "'i' Inventory\n" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice=="i") {
            InventoryGUI();

        } else if (std::stoi(choice) > 0 and std::stoi(choice) <= m_player->getAbilities().size()) {
            auto ability = m_player->getAbility(std::stoi(choice)-1);
            if (ability->getName()!="Slash") {
                enemy->takeDamage(ability->doDamage(0,m_player->getStrenght()));
            } else {
                enemy->takeDamage(ability->doDamage(m_player->getWeaponDamage(),m_player->getStrenght()));
            }
            m_combat->nextTurn();

        }

    } else {
        std::cout << "          Enemy turn" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));

        m_player->takeDamage(m_combat->enemyDamageFromAction());

        std::cout << "\n          Enemy used Punch!" << std::endl; //debug
        std::this_thread::sleep_for(std::chrono::seconds(2));

        m_combat->nextTurn();
    }




}

void GameLogic::Game::printAbilityOverview() {
    auto abilities = m_player->getAbilities();
         std::cout << "Abilities:" << std::endl;
    for (int i = 0; i < abilities.size(); ++i) {
        std::cout << i+1 << ". " << abilities[i]->getName() << "  ";
    }
}



void GameLogic::Game::printItemDetails(std::string type, Entities::Item *item) {

    if (item->getItemType() != Entities::ItemType::relic) {
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
        std::cout << "Item type:        consumable\n" << std::endl;

    }

}



void GameLogic::Game::printTutorial() {
    std::string input;
    std::cout << "|---------Tutorial and controls---------|\n" << std::endl;
    std::cout << "Welcome in the game <name>!" << std::endl;
    std::cout << "In this game your task is to make it through the dungeon!" << std::endl;
    std::cout << "Be careful as there will be many thigs that will try to stop you!" << std::endl;
    std::cout << "Press Enter to continue" << std::endl; //change to getch
    std::cin >> input;
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
    << "     E - Enemy" << std::endl
    << "     I - Item" << std::endl
    << "     P - Player (you)" << std::endl
    << "     Free space - Floor\n\n" << std::endl;

    std::cout << "        Controls:" << std::endl
    << "     w,a,s,d - Movement" << std::endl
    << "     x - Exit game" << std::endl
    << "     i - Inventory\n" << std::endl;

    std::cout << "Press any key to continue " << std::endl; //change to getch
    std::cin >> input;
    clearScreen();
}

bool GameLogic::Game::isPlayerAlive() {
    return m_player->isAlive();
}


void GameLogic::Game::printGameScreen() {
    std::cout << "\n" << "      Room " << m_currentMap+1 << std::endl;
    std::cout << "\n";

    printMap(m_currentMap);
    std::cout << "\n";

    std::cout << "    Player: " << m_player->getName() <<
    "  [" << m_player->getHealth() << "/" << m_player->getMaxHealth() << "]\n" <<std::endl;

    std::cout << "        Controls:" << std::endl
              << "     w,a,s,d - Movement" << std::endl
              << "     x - Exit game" << std::endl
              << "     i - Inventory\n" << std::endl;
}


void GameLogic::Game::mapMovement(char pressedKey, int xPlayerCordinate, int yPlayerCordinate) {
    std::array<int, 2> cordinates = m_player->getPlayerPosition();
    //finish

}