#include <iostream>
#include "Player/Player.h"



int main() {


    Player::Player* hrac = new Player::Player("Player");

    Entities::Consumable* potak = new Entities::Consumable("Minor potion", "heals 10 hp", 10);



    hrac->setHealth(50);

    std::cout << hrac->getHealth() << std::endl;

    hrac->useReplenishment(potak);

    std::cout << hrac->getHealth() << std::endl;

    return 0;
}


