//
// Created by Krystian Wasil on 11/01/2024.
//

#ifndef ROGUELIKE_POTION_H
#define ROGUELIKE_POTION_H


#include "Item.h"

class Potion : public Item{
public:
    Potion() : Item('h',0,0,10,1,0,"Potion") {}
};


#endif //ROGUELIKE_POTION_H
