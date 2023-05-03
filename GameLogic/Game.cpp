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
        std::cout << "Nahoru" << std::endl;
        return true;
    } else if(input == 'a') {
        std::cout << "Doleva" << std::endl;
        return true;
    } else if(input == 's') {
        std::cout << "Dolu" << std::endl;
        return true;
    } else if(input == 'd') {
        std::cout << "Doprava" << std::endl;
        return true;
    } else if(input == 'x') {
        std::cout << "Exit" << std::endl;
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


void GameLogic::Game::printMap() {
    std::cout << "yoooo" << std::endl; //debug

}

void GameLogic::Game::clearScreen() {
    system("cls"); //debug
}

void GameLogic::Game::printPlayer() { //debug
    std::cout << m_player->getName();
}



bool GameLogic::Game::combat() {
    bool combat = true;
    auto enemy = new Entities::Enemy("skeleton", 50, 10, 5); //debug
    m_combat->beginCombat(m_player,enemy); //debug

    while (combat) {
        combatGUI(enemy);

        if (m_combat->checkAliveStatus() != "bothAlive") {
            combat = false;
        }

        m_combat->nextTurn();
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
        std::cout <<"          " << i << "    " << inventory[i]->getName() << std::endl;
    }

    std::string input;
    std::cout << "\nEnter item number or 'q' to exit: ";
    std::cin >> input;

    if (input=="q") {

    } else if (std::stoi(input) >=0 and std::stoi(input) <= inventory.size()) {
        clearScreen();
       // Entities::Item* pickedItem = inventory[input]; nefunguje
       int pickedItemIndex = std::stoi(input);

        if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::armor) {
            std::cout << "Item name:        " << inventory[pickedItemIndex]->getName() << std::endl;
            std::cout << "Item description: " << inventory[pickedItemIndex]->getInfo() << std::endl;
            std::cout << "Item type:        armor" << std::endl;
            if (inventory[pickedItemIndex] == m_player->getEquippedArmor()) {
                std::cout << "Item status:      Equipped" << std::endl;
            } else {
                std::cout << "Item status:    -    \n" << std::endl;
            }

        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::relic) {
            std::cout << "Item name:        " << inventory[pickedItemIndex]->getName() << std::endl;
            std::cout << "Item description: " << inventory[pickedItemIndex]->getInfo() << std::endl;
            std::cout << "Item type:        relic" << std::endl;
            if (inventory[pickedItemIndex] == m_player->getEquippedRelic()) {
                std::cout << "Item status:      Equipped" << std::endl;
            } else {
                std::cout << "Item status:        -    \n" << std::endl;
            }

        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::weapon) {
            std::cout << "Item name:        " << inventory[pickedItemIndex]->getName() << std::endl;
            std::cout << "Item description: " << inventory[pickedItemIndex]->getInfo() << std::endl;
            std::cout << "Item type:        weapon" << std::endl;
            if (inventory[pickedItemIndex] == m_player->getEquippedWeapon()) {
                std::cout << "Item status:      Equipped" << std::endl;
            } else {
                std::cout << "Item status:      -    \n" << std::endl;
            }

        } else if (inventory[pickedItemIndex]->getItemType() == Entities::ItemType::consumable) {
            std::cout << "Item name:        " << inventory[pickedItemIndex]->getName() << std::endl;
            std::cout << "Item description: " << inventory[pickedItemIndex]->getInfo() << std::endl;
            std::cout << "Item type:        consumable\n" << std::endl;
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
            if (ability->getName()!="slash") {
                enemy->takeDamage(ability->doDamage(0,m_player->getStrenght()));
            } else {
                enemy->takeDamage(ability->doDamage(m_player->getWeaponDamage(),m_player->getStrenght()));
            }

        }

    } else {
        std::cout << "          Enemy turn" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (enemy->getAbilities().size()==1){
            m_player->takeDamage(m_combat->enemyDamageFromAction(0));
        }
    }







}

void GameLogic::Game::printAbilityOverview() {
    auto abilities = m_player->getAbilities();
         std::cout << "Abilities:" << std::endl;
    for (int i = 0; i < abilities.size(); ++i) {
        std::cout << i+1 << ". " << abilities[i]->getName() << "  ";
    }
}