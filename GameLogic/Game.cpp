//
// Created by xkapp on 29.04.2023.
//

#include "Game.h"
#include <iostream>
#include <stdlib.h>
#define ASCII_ESC 27

GameLogic::Game::Game(Player::Player *player, GameLogic::Combat *combat) {
    m_player = player;
    m_combat = combat;
    m_currentMap = 0;
}

void GameLogic::Game::printMap() {
    std::cout << "yoooo" << std::endl; //debug

}

void GameLogic::Game::clearScreen() {
    system("cls"); //debug
}

void GameLogic::Game::printPlayer() {
    std::cout << m_player->getName();
}