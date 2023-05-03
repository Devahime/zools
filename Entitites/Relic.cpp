//
// Created by xkapp on 21.04.2023.
//



#include "Relic.h"
#include <string>


Entities::Relic::Relic(std::string name, std::string info, int healthBonus, int strenghtBonus): Item(name, info, ItemType::relic) {
    m_healthBonus = healthBonus;
    m_stenghtBonus = strenghtBonus;
}

int Entities::Relic::getHealthBonus() {
    return m_healthBonus;
}

int Entities::Relic::getStrenghtBonus() {
    return m_stenghtBonus;
}

