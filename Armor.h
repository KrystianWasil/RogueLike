//
// Created by wasil on 21.12.2023.
//

#ifndef ROGUELIKE_ARMOR_H
#define ROGUELIKE_ARMOR_H


#include "Item.h"

class Armor : public Item {
public:
    Armor() : Item('M',0,5,0.5,0,0,"Armor") {}
};


#endif //ROGUELIKE_ARMOR_H
