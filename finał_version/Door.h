//
// Created by Krystian Wasil on 26/01/2024.
//

#ifndef ROGUELIKE_DOOR_H
#define ROGUELIKE_DOOR_H


#include "Tile.h"

class Door : public Tile {
public:
    Door() : Tile('?') {}
};


#endif //ROGUELIKE_DOOR_H
