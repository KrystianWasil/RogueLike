//
// Created by wasil on 21.12.2023.
//

#ifndef ROGUELIKE_GUN_H
#define ROGUELIKE_GUN_H


#include "Item.h"

class Gun : public Item{
public:
    Gun() : Item('<',12,0,0,0,0,"Gun") {}
};


#endif //ROGUELIKE_GUN_H
