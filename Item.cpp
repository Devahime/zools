//
// Created by xkapp on 18.04.2023.
//

#include "Item.h"


Entities::Item::Item(std::string name, std::string info) {
    m_name = name;
    m_info = info;
}

std::string Entities::Item::getName() {
    return m_name;
}

std::string Entities::Item::getInfo() {
    return m_info;
}

