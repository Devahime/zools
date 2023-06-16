//
// Created by xkapp on 16.06.2023.
//

#include "GUI.h"
#include "iostream"

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