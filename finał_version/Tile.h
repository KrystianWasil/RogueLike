#ifndef GAMEROGUELIKE_FIELD_H
#define GAMEROGUELIKE_FIELD_H

#include <memory>
#include "Entity.h"
#include "Item.h"

class Tile {
private:
    char representation;
    std::shared_ptr<Entity> entity;
    std::shared_ptr<Item> item;

public:
    explicit Tile(char representation) : representation(representation) {}

    char getRepresentation() const {
        return representation;
    }

    void setRepresentation(char representation) {
        Tile::representation = representation;
    }

    std::shared_ptr<Entity> getEntity() const {
        return entity;
    }

    void setEntity(const std::shared_ptr<Entity>& entity) {
        this->entity = entity;
    }

    std::shared_ptr<Item> getItem() const {
        return item;
    }

    void setItem(const std::shared_ptr<Item>& item) {
        this->item = item;
    }
};

#endif //GAMEROGUELIKE_FIELD_H
