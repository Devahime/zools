//
// Created by xkapp on 29.04.2023.
//

#include "Game.h"
#include <iostream>
#include <stdlib.h>
//#define ASCII_ESC 27
#include "../Entitites/ItemType.h"

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
    } else if(input == 'c') {  //debug

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
    m_combat->beginCombat(m_player,new Entities::Enemy("skeleton", 50, 10, 10)); //debug

    while (combat) {

    }

}



void GameLogic::Game::InventoryGUI() {
    clearScreen();
    std::vector<Entities::Item*> inventory = m_player->getInvenotry();
    std::cout << "Write number of item you want to use \n" << std::endl;
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
        if (inventory[std::stoi(input)]->getItemType() == Entities::ItemType::armor) {
            
        }
    }



}