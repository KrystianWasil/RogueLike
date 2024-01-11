//
// Created by wasil on 21.12.2023.
//

#ifndef ROGUELIKE_KNIFE_H
#define ROGUELIKE_KNIFE_H


#include "Item.h"

class Knife : public Item {
public:
    Knife() : Item('k',4,0,0,2,0,"Knife") {}
};


#endif //ROGUELIKE_KNIFE_H
