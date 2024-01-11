//
// Created by wasil on 12.12.2023.
//

#ifndef ROGUELIKE_HUNGRYDOG_H
#define ROGUELIKE_HUNGRYDOG_H


#include "Entity.h"

class HungryDog : public Entity {
public:
    HungryDog() : Entity('D',"dogo",100, 2, 2,0, 0, 0, 1,0,{},{}) {}
};


#endif //ROGUELIKE_HUNGRYDOG_H
