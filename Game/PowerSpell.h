//
// Created by wasil on 21.12.2023.
//

#ifndef ROGUELIKE_POWERSPELL_H
#define ROGUELIKE_POWERSPELL_H


#include "Item.h"

class PowerSpell : public Item{
public:
    PowerSpell() : Item('o', 0, 0, 0, 0, 8,"PowerSpell") {}
};


#endif //ROGUELIKE_POWERSPELL_H
