#ifndef GAMEROGUELIKE_FIELD_H
#define GAMEROGUELIKE_FIELD_H

#include <vector>
#include "Obstacles.h"
#include "Entity.h"
#include "Item.h"
class Tile {
private:
    char representation;
    Entity *entity;
protected:
    std::vector<Item*> items;
    std::vector<Obstacles*> obstacles;
    int numberOfObstacles = 0;
    int numberOfItems = 0;
public:
    Tile(char representation, const std::vector<Obstacles*> &obstacles) : representation(representation), obstacles(obstacles) {}

    [[nodiscard]] char getRepresentation() const {
        return representation;
    }

    void setRepresentation(char newRep) {
        Tile::representation = newRep;
    }

    void setEntity(Entity *entity) {
       this->entity = entity;
    }

    virtual void AddObstacles(Obstacles *obstacle);

    virtual void AddItems(Item *item);


};

#endif //GAMEROGUELIKE_FIELD_H
