#ifndef GAMEROGUELIKE_WALL_H
#define GAMEROGUELIKE_WALL_H

#include "Tile.h"

class Wall : public Tile {
public:
    Wall() : Tile('#') {}
};

#endif //GAMEROGUELIKE_WALL_H