//
// Created by xkapp on 18.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_ITEM_H
#define ZOOLS2023_XKADERK2_ITEM_H

#include <string>

namespace Entitites {
    class Item {
        std::string m_name;
        std::string m_info;

    public:
        Item(std::string name, std::string info);

        std::string getName();

        std::string getInfo();

    };

}







#endif //ZOOLS2023_XKADERK2_ITEM_H
