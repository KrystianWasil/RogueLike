//
// Created by Krystian Wasil on 01/02/2024.
//

#ifndef ROGUELIKE_KEY_H
#define ROGUELIKE_KEY_H


#include "Item.h"

class Key : public Item {
public:
    Key() : Item('?',0,0,10,0,0,"Key") {}
};


#endif //ROGUELIKE_KEY_H
