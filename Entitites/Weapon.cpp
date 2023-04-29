//
// Created by xkapp on 21.04.2023.
//

#include "Weapon.h"

Entities::Weapon::Weapon(std::string name, std::string info, int damage): Item(name, info) {
    m_damage = damage;
}

int Entities::Weapon::getDamage() {
    return m_damage;
}