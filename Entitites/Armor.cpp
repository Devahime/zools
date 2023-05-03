//
// Created by xkapp on 18.04.2023.
//

#include "Armor.h"

Entities::Armor::Armor(std::string name, std::string info, int armorValue): Item(name,info,ItemType::armor) {
    m_armorValue = armorValue;
}
///
int Entities::Armor::getArmorValue() {
    return m_armorValue;
}