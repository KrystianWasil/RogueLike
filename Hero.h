#ifndef ROGUELIKE_HERO_H
#define ROGUELIKE_HERO_H

#include "Entity.h"
#include "Item.h"

class Hero : public Entity {
public:
    Hero() : Entity('@', "Hero", 100, 10, 20, 0, 0, 10, 5, 0, {}, Item()) {}
};

#endif //ROGUELIKE_HERO_H
