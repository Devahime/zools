//
// Created by xkapp on 24.04.2023.
//

#include "Combat.h"

GameLogic::Combat::Combat() {
    reset();
}

void GameLogic::Combat::beginCombat(Player::Player *player, Entities::Enemy *enemy) {
    m_turn = 1;
    m_playersTurn = true;
    m_player = player;
    m_enemy = enemy;
}

void GameLogic::Combat::reset() {
    m_turn = 0;
    m_playersTurn = false;
    m_player = nullptr;
    m_enemy = nullptr;
}

void GameLogic::Combat::nextTurn() {

    m_turn += 1;
    if ((m_turn % 2) == 0) {
        m_player->lowerAbilityCooldown();
    }
    m_playersTurn = !m_playersTurn;
}

std::string GameLogic::Combat::checkAliveStatus() {
    if (m_player->isAlive() and m_enemy->isAlive()) {
        return "bothAlive";
    } else if (!m_player->isAlive()) {
        return "playerDead";
    } else {
        return "enemyDead";
    }
}

bool GameLogic::Combat::isPlayersTurn() {
    return m_playersTurn;
}

int GameLogic::Combat::enemyDamageFromAction() { //korektni čitelný zápis
    int strength = m_enemy->getStrenght();
    return m_enemy->getAbility()->doDamage(0,strength);
}