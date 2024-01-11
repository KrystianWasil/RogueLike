#ifndef GAMEROGUELIKE_FLOOR_H
#define GAMEROGUELIKE_FLOOR_H

#include "Tile.h"

class Floor : public Tile {

public:
    Floor() : Tile(' ', {}) {}

    void AddObstacles(Obstacles *obstacle) override {
        obstacles.push_back(obstacle);
        numberOfObstacles++;
    }

    void AddItems(Item *item) override {
        items.push_back(item);
        numberOfItems++;
    }


};

#endif //GAMEROGUELIKE_FLOOR_H
