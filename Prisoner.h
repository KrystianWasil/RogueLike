//
// Created by wasil on 23.11.2023.
//

#ifndef ROGUELIKE_PRISONER_H
#define ROGUELIKE_PRISONER_H


#include "Entity.h"

class Prisoner : public Entity {
public:
    Prisoner() : Entity('P',"prisoner",100, 10, 20,0, 0, 10, 5,0,{},{}) {}
};


#endif //ROGUELIKE_PRISONER_H
