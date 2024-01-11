#ifndef GAMEROGUELIKE_MAP_H
#define GAMEROGUELIKE_MAP_H

#include <iostream>
#include <vector>
#include "Tile.h"
#include "Wall.h"
#include "Floor.h"
#include "Obstacles.h"

class Map {
private:
    int rows, cols;
    std::vector<std::vector<Tile>> map;

public:
    Map(int rows, int cols) : rows(rows), cols(cols) {
        map.resize(rows, std::vector<Tile>(cols, Tile(' ', {})));
    }

    void InitMap() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    map[i][j] =  Wall();
                } else if (j > 0 && i > 0) {
                    map[i][j] = Floor();
                }
            }
    }

    void DisplayMap() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                std::cout << map[i][j].getRepresentation();
            std::cout << std::endl;
        }
    }

    void AddElement(Obstacles *obstacle, int x, int y) {
//        if (typeid(map[x][y]) == typeid(Floor)) {
            map[x][y].AddObstacles(obstacle);
            map[x][y].setRepresentation(obstacle->getRepresentation());
//        }
    }
    void AddItem (Item *item, int x, int y) {
        map[x][y].AddItems(item);
        map[x][y].setRepresentation(item->getRepresentation());
    }

    void AddActor(Entity *entity, int x, int y) {
        map[x][y].setRepresentation(entity->getRepresentation());
        map[x][y].setEntity(entity);
    }
};

#endif //GAMEROGUELIKE_MAP_H
