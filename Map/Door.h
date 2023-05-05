//
// Created by xinsanic on 28.04.2023.
//

#ifndef ZOOLS2023_XKADERK2_DOOR_H
#define ZOOLS2023_XKADERK2_DOOR_H

namespace Map{
    class Door {
    private:
        int m_targetRoom;
    public:
        Door();
        int getTargetRoom();
        void print();
    };
}


#endif //ZOOLS2023_XKADERK2_DOOR_H
