//
// Created by wasil on 12.12.2023.
//

#ifndef ROGUELIKE_MUTANTBAT_H
#define ROGUELIKE_MUTANTBAT_H


#include "Entity.h"

class MutantBat : public Entity{
public:
    MutantBat() : Entity(0,0,'B',"batman",500,15,20,30,0,0,2,10,{}) {}
};


#endif //ROGUELIKE_MUTANTBAT_H
