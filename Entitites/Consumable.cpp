//
// Created by xkapp on 21.04.2023.
//


#include "Consumable.h"
#include <string>

Entities::Consumable::Consumable(std::string name, std::string info, int replenishmentValue): Item(name, info, ItemType::consumable) {
    m_replenishmentValue = replenishmentValue;
}

int Entities::Consumable::getReplenishemntValue() {
    return m_replenishmentValue;
}