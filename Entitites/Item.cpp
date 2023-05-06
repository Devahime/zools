//
// Created by xkapp on 18.04.2023.
//

#include "Item.h"


Entities::Item::Item(std::string name, std::string info, ItemType itemType) {
    m_name = name;
    m_info = info;
    m_itemType = itemType;
}

std::string Entities::Item::getName() {
    return m_name;
}

std::string Entities::Item::getInfo() {
    return m_info;
}

Entities::ItemType Entities::Item::getItemType() {
    return m_itemType;
}