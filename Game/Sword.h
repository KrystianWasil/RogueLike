//
// Created by wasil on 21.12.2023.
//

#ifndef ROGUELIKE_SWORD_H
#define ROGUELIKE_SWORD_H


#include "Item.h"

class Sword : public Item{
public:
    Sword() : Item('!',16,0,0,-1.f,3,"Sword") {}
};


#endif //ROGUELIKE_SWORD_H
