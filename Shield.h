//
// Created by wasil on 21.12.2023.
//

#ifndef ROGUELIKE_SHIELD_H
#define ROGUELIKE_SHIELD_H


#include "Item.h"

class Shield : public Item {
public:
    Shield() : Item('O',0,8,1,0,0,"Shield") {}
};


#endif //ROGUELIKE_SHIELD_H
