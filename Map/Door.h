//
// Created by xinsanic on 28.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_DOOR_H
#define ZOOLS2023_XKADERK2_DOOR_H
#include "Tile.h"

namespace Map{
    class Door : public Tile{
    private:
        int m_targetRoom;
    public:
        Door();
        int getTargetRoom();
        void print();
    };
}


#endif //ZOOLS2023_XKADERK2_DOOR_H
