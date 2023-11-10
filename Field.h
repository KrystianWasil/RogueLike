#ifndef GAMEROGUELIKE_FIELD_H
#define GAMEROGUELIKE_FIELD_H

#include <vector>
#include "Obstacles.h"

class Field {
private:
    char representation;
    std::vector<Obstacles> obstacles;
    int numberOfObstacles = 0;

public:
    Field(char representation, const std::vector<Obstacles> &obstacles) : representation(representation),obstacles(obstacles) {}

    char getRepresentation() const {
        return representation;
    }

    void AddObstacles(Obstacles obstacle) {
        obstacles[numberOfObstacles+1] = obstacle;
        numberOfObstacles++;
    }
};

#endif //GAMEROGUELIKE_FIELD_H
