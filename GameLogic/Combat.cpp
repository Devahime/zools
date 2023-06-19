//
// Created by xkapp on 24.04.2023.
//

#include "Combat.h"
#include "../Player/Kick.h"
#include "../Player/Ability.h"
#include "../Player/Slash.h"
#include "../Player/Punch.h"
#include "iostream"
#include <chrono>
#include <thread>

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

void GameLogic::Combat::playerCombatAction(int abilityIndex) {
    //parameter is index of player abilites which he chose in game->combatGUI
    auto ability = m_player->getAbility(abilityIndex);
    if (ability->getName() =="Punch") {
        m_enemy->takeDamage(ability->doDamage(0,m_player->getStrenght()));
        nextTurn();
    } else if (ability->getName() == "Kick") {
        if (static_cast<Player::Kick*>(ability)->getCooldownTimer() == 0) {
            m_enemy->takeDamage((static_cast<Player::Kick*>(ability)->doDamage(0, m_player->getStrenght())));
            nextTurn();
        } else {
            std::cout << "There is a cooldown on this ability in this turn! You need to wait " <<
            static_cast<Player::Kick*>(ability)->getCooldownTimer() << " more turn(s). Use another ability." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }

    } else {
        //slash
        m_enemy->takeDamage(ability->doDamage(m_player->getPlayerInvenotry()->getWeaponDamage() ,m_player->getStrenght()));
        nextTurn();
    }
}

void GameLogic::Combat::enemyCombatAction() {
    //enemy turn
    m_player->takeDamage(enemyDamageFromAction());
    //once enemy finished casting his ability, player again will have turn in next function calling
    nextTurn();
}