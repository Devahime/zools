//
// Created by xkapp on 18.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ITEM_H
#define ZOOLS2023_XKADERK2_ITEM_H

#include <string>
#include "ItemType.h"

namespace Entities {
    class Item {
        /**
         * This class represents an item, which can do several things.
         * This class is only a "template" with basic variables that all Children of this class will inherit.
         * The only fucntions are getters for the basic variables.
         * Each type of items has its own children class which does all the fucntionality.
         */
    protected:
        std::string m_name;
        std::string m_info;
        Entities::ItemType m_itemType;

    public:
        Item(std::string name, std::string info, ItemType itemType);

        std::string getName();

        std::string getInfo();

        Entities::ItemType getItemType();

    };

}







#endif //ZOOLS2023_XKADERK2_ITEM_H
