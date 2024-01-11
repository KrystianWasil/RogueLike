//
// Created by wasil on 12.12.2023.
//

#ifndef ROGUELIKE_GUARD_H
#define ROGUELIKE_GUARD_H


#include "Entity.h"

class Guard : public Entity{
public:
    Guard() : Entity('G', "guardiano", 100, 10, 20, 0, 0, 10, 5, 0,{},Item()) {}
};


#endif //ROGUELIKE_GUARD_H
