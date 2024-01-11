//
// Created by wasil on 10.11.2023.
//

#ifndef GAMEROGUELIKE_OBSTACLES_H
#define GAMEROGUELIKE_OBSTACLES_H


class Obstacles {
private:
    char representation;
public:
    explicit Obstacles(char representation) : representation(representation){}

    [[nodiscard]] char getRepresentation() const {
        return representation;
    }

//    void setRepresentation(char rep) {
//        Obstacles::representation = rep;
//    }
};


#endif //GAMEROGUELIKE_OBSTACLES_H
