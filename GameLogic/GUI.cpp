//
// Created by xkapp on 16.06.2023.
//

#include "GUI.h"
#include "iostream"
#include <conio.h>

void GameLogic::GUI::clearScreen() {
    system("cls");
}

void GameLogic::GUI::printInventory(std::vector<Entities::Item *> inventory, Player::Player *player) {
    clearScreen();

    std::cout << "|-------------Inventory------------|  Player: "
              <<player->getName() << " [" << player->getHealth() << "/"<<  player->getMaxHealth() << "]\n" << std::endl;
    std::cout << "Item number    Item name" << std::endl;

    // printing the list of items in inventory
    for (int i = 0; i < inventory.size(); ++i) {
        std::cout <<"          " << i+1 << "    " << inventory[i]->getName() << std::endl;
    }
    std::cout << "\nEnter item number to make item action or 'q' to exit: ";
}

void GameLogic::GUI::printArmorInfo(Entities::Armor *armor, bool isEquipped) {
    std::cout << "Item name:        " << armor->getName() << std::endl;
    std::cout << "Item description: " << armor->getInfo() << std::endl;
    std::cout << "Item type:        " << "Armor" << std::endl;
    std::cout << "Armor value:      " << armor->getArmorValue() << std::endl;
    if (isEquipped) {
        std::cout << "Item status:      " << "equipped" << std::endl;
    } else {
        std::cout << "Item status:      " << "   -" << std::endl;
    }
}

void GameLogic::GUI::printWeaponInfo(Entities::Weapon *weapon, bool isEquipped) {
    std::cout << "Item name:        " << weapon->getName() << std::endl;
    std::cout << "Item description: " << weapon->getInfo() << std::endl;
    std::cout << "Item type:        " << "Weapon" << std::endl;
    std::cout << "Weapon damage:    " << weapon->getDamage() << std::endl;
    if (isEquipped) {
        std::cout << "Item status:      " << "equipped" << std::endl;
    } else {
        std::cout << "Item status:      " << "   -" << std::endl;
    }
}

void GameLogic::GUI::printRelicInfo(Entities::Relic *relic, bool isEquipped) {
    std::cout << "Item name:        " << relic->getName() << std::endl;
    std::cout << "Item description: " << relic->getInfo() << std::endl;
    std::cout << "Item type:        " << "Relic" << std::endl;
    std::cout << "Strenght bonus:   " << relic->getStrenghtBonus() << std::endl;
    std::cout << "Health bonus:   " << relic->getHealthBonus() << std::endl;
    if (isEquipped) {
        std::cout << "Item status:      " << "equipped" << std::endl;
    } else {
        std::cout << "Item status:      " << "   -" << std::endl;
    }
}

void GameLogic::GUI::printConsumableInfo(Entities::Consumable *consumable) {
    std::cout << "Item name:        " << consumable->getName() << std::endl;
    std::cout << "Item description: " << consumable->getInfo() << std::endl;
    std::cout << "Item type:        " << "Consumable" << std::endl;
    std::cout << "Heal value:       " << consumable->getReplenishemntValue() << std::endl;

}

void GameLogic::GUI::printTutorial(Player::Player *player) {
    std::string input;
    std::cout << "|---------Tutorial and controls---------|\n" << std::endl;
    std::cout << "Welcome to the game "<< player->getName() << "!" << std::endl;
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
}