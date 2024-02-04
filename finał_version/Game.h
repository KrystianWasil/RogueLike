// Created by wasil on 23.11.2023.
//

#ifndef GAMEROGUELIKE_MAP_H
#define GAMEROGUELIKE_MAP_H

#include <iostream>
#include <utility>
#include <vector>
#include <random>
#include "Tile.h"
#include "Wall.h"
#include "Floor.h"
#include "Potion.h"
#include "Sword.h"
#include "Shoes.h"
#include "Shield.h"
#include "PowerSpell.h"
#include "Knife.h"
#include "Gun.h"
#include "Guard.h"
#include "HungryDog.h"
#include "OldWizard.h"
#include "MutantBat.h"
#include "Entity.h"
#include "Door.h"
#include "Stroller.h"
#include "Armor.h"
#include "Key.h"
#include <stack>
#include <cstdlib>
#include <ctime>
#include <memory>

class Game {
private:
    int rows, cols;
    std::vector<std::vector<std::shared_ptr<Tile>>> map;
    std::vector<std::shared_ptr<Item>> Items;
    std::vector<std::shared_ptr<Entity>> Mobs;
    std::vector<std::pair<int, int>> pointsFloor;
    std::shared_ptr<Entity> Hero;
    int sizeOfPointsArray = 0;
    int level = 0;

public:
    Game(int rows, int cols) : rows(rows), cols(cols) {
        map.resize(rows, std::vector<std::shared_ptr<Tile>>(cols, std::make_shared<Wall>()));
    }

    [[nodiscard]] const std::vector<std::shared_ptr<Entity>> &getMobs() const {
        return Mobs;
    }
    void addHeroOnMap() {
        std::random_device rd1;
        std::mt19937 gen1(rd1());
        int x, y;
        while (true) {
            std::uniform_int_distribution<int> cube(0, (int)(pointsFloor.size() - 1));
            x = pointsFloor.at(cube(gen1)).first;
            y = pointsFloor.at(cube(gen1)).second;
            if (map.at(y).at(x)->getRepresentation() != '#' &&
                map.at(y).at(x)->getEntity() == nullptr &&
                map.at(y).at(x)->getItem() == nullptr) {
                break;
            }
        }
        Hero->setX(x);
        Hero->setY(y);
        map.at(y).at(x)->setEntity(Hero);
        map.at(y).at(x)->setRepresentation(Hero->getRepresentation());
    }

    void SetHeroOnMap(std::shared_ptr<Entity> hero) {
        this->Hero = std::move(hero);
    }

    [[nodiscard]] bool isInsideMap(std::pair<int, int> point, int roomWidth, int roomHeight) const {
        int roomX1 = point.first - roomWidth / 2;
        int roomX2 = point.first + roomWidth / 2;
        int roomY1 = point.second - roomHeight / 2;
        int roomY2 = point.second + roomHeight / 2;

        if (roomX1 > 0 && roomX2 < this->cols - 1 &&
            roomY1 > 0 && roomY2 < this->rows - 1) {
            return true;
        }

        return false;
    }

    void InitMap() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                map.at(i).at(j) = std::make_shared<Wall>();
            }
    }

    void GenerateRoom(std::pair<int, int> point, int w, int h) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> cube1(0,100);
        int startX = point.first - w / 2;
        int endX = point.first + w / 2;
        int startY = point.second - h / 2;
        int endY = point.second + h / 2;

        startX = (startX < 0) ? 0 : startX;
        startY = (startY < 0) ? 0 : startY;

        endX = (endX >= cols) ? cols - 1 : endX;
        endY = (endY >= rows) ? rows - 1 : endY;
        int chance = cube1(gen);
        if (chance >= 20) {
            for (int i = startY; i <= endY; ++i) {
                for (int j = startX; j <= endX; ++j) {
                    map.at(i).at(j) = std::make_shared<Floor>();
                    std::pair<int, int> point_to_array;
                    point_to_array.first = j;
                    point_to_array.second = i;
                    pointsFloor.push_back(point_to_array);
                    sizeOfPointsArray++;
                }
            }
        } else {
            for (int i = startY; i <= endY; ++i) {
                for (int j = startX; j <= endX; ++j) {
                    map.at(i).at(j) = std::make_shared<Stroller>();
                    std::pair<int, int> point_to_array;
                    point_to_array.first = j;
                    point_to_array.second = i;
                    pointsFloor.push_back(point_to_array);
                    sizeOfPointsArray++;
                }
            }
        }
    }

    void GenerateTunnels(const std::pair<int, int>& start, const std::pair<int, int>& end) {
        int currentX = start.first;
        int currentY = start.second;

        while (currentX != end.first) {
            map.at(currentY).at(currentX) = std::make_shared<Floor>();
            map.at(currentY).at(currentX - 1) = std::make_shared<Floor>();
            currentX += (currentX < end.first) ? 1 : -1;
        }

        while (currentY != end.second) {
            map.at(currentY).at(currentX) = std::make_shared<Floor>();
            map.at(currentY).at(currentX - 1) = std::make_shared<Floor>();
            currentY += (currentY < end.second) ? 1 : -1;
        }
    }

    void GenerateRandomItems() {
        for (auto &Item : Items) {
            std::random_device rd;
            std::mt19937 gen(rd());

            int x, y;
            while (true) {
                std::uniform_int_distribution<int> cube(0, int(pointsFloor.size() - 1));
                x = pointsFloor.at(cube(gen)).first;
                y = pointsFloor.at(cube(gen)).second;
                if (map.at(y).at(x)->getRepresentation() != '#')
                    break;
            }

            AddItem(Item, x, y);
        }
        Items.clear();
    }

    void GenerateRandomMobs() {
        for (auto &Mob : Mobs) {
            std::random_device rd1;
            std::mt19937 gen1(rd1());

            int x, y;
            while (true) {
                std::uniform_int_distribution<int> cube1(0, int(pointsFloor.size() - 1));
                x = pointsFloor.at(cube1(gen1)).first;
                y = pointsFloor.at(cube1(gen1)).second;
                if (map.at(y).at(x)->getRepresentation() != '#')
                    break;
            }

            Mob->setX(x);
            Mob->setY(y);
            AddActor(Mob, x, y);
        }
    }



    void GenerateDungeons(int level) {
        InitMap();
        std::random_device rd;
        std::mt19937 gen(rd());

        std::pair<int, int> point, previous_point;
        int height, width;
        int min1 = 1;
        int max1 = 59;
        int min2 = 2;
        int max2 = 16;

        for (int i = 0; i < 5; ++i) {
            do {
                std::uniform_int_distribution<int> dist(min1, max1);
                std::uniform_int_distribution<int> dist2(min2, max2);
                int x = dist(gen);
                int y = dist(gen);
                height = dist2(gen);
                width = dist2(gen) + 2;
                point = {x, y};
            } while (!isInsideMap(point, width, height));

            GenerateRoom(point, width, height);
            if (i > 0) {
                GenerateTunnels(point, previous_point);
            }
            previous_point = point;
        }

        Level(level);
        GenerateRandomItems();
        GenerateRandomMobs();
        addHeroOnMap();
        pointsFloor.clear();
        sizeOfPointsArray = 0;
    }

    void AddElementToLevel(const std::shared_ptr<Item>& item) {
        Items.push_back(item);
    }

    void Level( int level) {
        ClearItems();
        ClearMobs();
        switch (level) {
            case 0:
                AddMobsToLevel(std::make_shared<HungryDog>());
                AddMobsToLevel(std::make_shared<HungryDog>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Knife>());
                AddElementToLevel(std::make_shared<Key>());
                break;

            case 1:
                AddMobsToLevel(std::make_shared<HungryDog>());
                AddMobsToLevel(std::make_shared<HungryDog>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Knife>());
                AddMobsToLevel(std::make_shared<Guard>());
                AddElementToLevel(std::make_shared<Shield>());
                AddElementToLevel(std::make_shared<Key>());
                break;

            case 2:
                AddMobsToLevel(std::make_shared<HungryDog>());
                AddMobsToLevel(std::make_shared<HungryDog>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Knife>());
                AddMobsToLevel(std::make_shared<Guard>());
                AddElementToLevel(std::make_shared<Shield>());
                AddMobsToLevel(std::make_shared<Prisoner>());
                AddElementToLevel(std::make_shared<Shoes>());
                AddElementToLevel(std::make_shared<Gun>());
                AddElementToLevel(std::make_shared<PowerSpell>());
                AddElementToLevel(std::make_shared<Sword>());
                AddElementToLevel(std::make_shared<Key>());
                break;

            case 3:
                AddMobsToLevel(std::make_shared<Guard>());
                AddMobsToLevel(std::make_shared<Prisoner>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Gun>());
                AddElementToLevel(std::make_shared<PowerSpell>());
                AddElementToLevel(std::make_shared<Key>());
                break;

            case 4:
                AddMobsToLevel(std::make_shared<OldWizard>());
                AddMobsToLevel(std::make_shared<Guard>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Sword>());
                AddElementToLevel(std::make_shared<Shoes>());
                AddElementToLevel(std::make_shared<Shield>());
                AddElementToLevel(std::make_shared<Armor>());
                AddElementToLevel(std::make_shared<Key>());
                break;

            case 5:
                AddMobsToLevel(std::make_shared<MutantBat>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Potion>());
                AddElementToLevel(std::make_shared<Sword>());
                AddElementToLevel(std::make_shared<PowerSpell>());
                AddElementToLevel(std::make_shared<Armor>());
                AddElementToLevel(std::make_shared<Knife>());
                AddElementToLevel(std::make_shared<Gun>());
                AddMobsToLevel(std::make_shared<Guard>());
                AddElementToLevel(std::make_shared<Key>());
                break;

            default:
                // Handle other levels or provide a default case
                break;
        }
    }

    void AddMobsToLevel(const std::shared_ptr<Entity>& entity) {
        Mobs.push_back(entity);
    }

    void ClearMobs() {
        Mobs.clear();
    }

    void ClearItems() {
        Items.clear();
    }

    void DisplayMap() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                std::cout << map.at(i).at(j)->getRepresentation();
            std::cout << std::endl;
        }
    }

    void AddItem(const std::shared_ptr<Item>& item, int x, int y) {
        map.at(y).at(x)->setItem(item);
        map.at(y).at(x)->setRepresentation(item->getRepresentation());
    }

    void AddActor(const std::shared_ptr<Entity>& entity, int x, int y) {
        map.at(y).at(x)->setRepresentation(entity->getRepresentation());
        map.at(y).at(x)->setEntity(entity);
    }



    std::shared_ptr<Entity> isHeroAround(const std::shared_ptr<Entity>& entity) {
        if (map.at(entity->getPosition().second - 1).at(entity->getPosition().first)->getEntity() != nullptr) {
            return map.at(entity->getPosition().second - 1).at(entity->getPosition().first)->getEntity();
        }
        else if (map.at(entity->getPosition().second + 1).at(entity->getPosition().first)->getEntity() != nullptr) {
            return map.at(entity->getPosition().second + 1).at(entity->getPosition().first)->getEntity();
        }
        else if (map.at(entity->getPosition().second).at(entity->getPosition().first + 1)->getEntity() != nullptr) {
            return map.at(entity->getPosition().second).at(entity->getPosition().first + 1)->getEntity();
        }
        else if (map.at(entity->getPosition().second).at(entity->getPosition().first - 1)->getEntity() != nullptr) {
            return map.at(entity->getPosition().second).at(entity->getPosition().first - 1)->getEntity();
        } else {
            return nullptr;
        }

    }


    void Mob(const std::shared_ptr<Entity>& entity) { //,bool &flag
        std::random_device rd;
        std::mt19937 gen(rd());
        int d[] = {-1, 0, 1, 0};
        int currentX = entity->getPosition().first;
        int currentY = entity->getPosition().second;
        int newX, newY;
        std::uniform_int_distribution<int> i(0, 3);


        if ( entity->getHealth() >= 30 && isHeroAround(entity) != nullptr && isHeroAround(entity)->getRepresentation() == '@') {

            if (isHeroAround(entity)->isAlive()) {
                entity->attack(isHeroAround(entity));
            }
        } else if (entity->isAlive()) {
            while (true) {
                newX = currentX + d[i(gen)];
                newY = currentY + d[i(gen)];

                if (newX >= 0 && newX < cols && newY >= 0 && newY < rows &&
                    map.at(newY).at(newX)->getRepresentation() != '#' &&
                    map.at(newY).at(newX)->getEntity() == nullptr && map.at(newY).at(newX)->getItem() == nullptr && map.at(newY).at(newX)->getRepresentation() != '?') {
                    break;
                }
            }

            if (map.at(currentY).at(currentX)->getItem() != nullptr) {
                map.at(currentY).at(currentX)->setRepresentation(map.at(currentY).at(currentX)->getItem()->getRepresentation());
            } else {
                map.at(currentY).at(currentX)->setRepresentation(' ');
            }

            map.at(currentY).at(currentX)->setEntity(nullptr);
            map.at(newY).at(newX)->setEntity(entity);
            map.at(newY).at(newX)->setRepresentation(entity->getRepresentation());
            entity->setX(newX);
            entity->setY(newY);
        } else {
            map.at(currentY).at(currentX)->setEntity(nullptr);
            if ( map.at(currentY).at(currentX)->getItem() != nullptr) {
                map.at(currentY).at(currentX)->setRepresentation( map.at(currentY).at(currentX)->getItem()->getRepresentation());
            }else {
                map.at(currentY).at(currentX)->setRepresentation('x');
            }
//            flag = true;
        }

    }



    void EntityMoving(char key, const std::shared_ptr<Entity>& hero) {
        int currentX = hero->getPosition().first;
        int currentY = hero->getPosition().second;


        map.at(currentY).at(currentX)->setEntity(nullptr);
        if (map.at(currentY).at(currentX)->getItem() != nullptr)
            map.at(currentY).at(currentX)->setRepresentation(
                    map.at(currentY).at(currentX)->getItem()->getRepresentation());
        else {
            map.at(currentY).at(currentX)->setRepresentation(' ');
        }
        if (isHeroAround(hero) != nullptr) {
            std::cout << "Enemy hp: " << isHeroAround(hero)->getHealth() << "\n";
            std::cout << " Do you want to hit this enemy ??? (y/n)\n";
            char type_key;
            std::cin >> type_key;
            if (type_key == 'y') {
                if (isHeroAround(hero)->isAlive()) {
                    hero->attack(isHeroAround(hero));
                    if (!isHeroAround(hero)->isAlive()) {
                        hero->addKills();
                    }
                }
            }
        }


        switch (key) {
            case 'w':
                if (currentY > 0 && map.at(currentY - 1).at(currentX)->getEntity() == nullptr &&
                    map.at(currentY - 1).at(currentX)->getRepresentation() != '#') {
                    hero->setY(currentY - 1);
                    if (map.at(currentY - 1).at(currentX)->getRepresentation() == '_') {
                        hero->setSpeed(hero->getSpeed()-0.2);
                    }
                }
                break;
            case 'a':
                if (currentX > 0 && map.at(currentY).at(currentX - 1)->getEntity() == nullptr &&
                    map.at(currentY).at(currentX - 1)->getRepresentation() != '#') {
                    hero->setX(currentX - 1);
                    if (map.at(currentY).at(currentX - 1)->getRepresentation() == '_') {
                        hero->setSpeed(hero->getSpeed()-0.2);
                    }
                }
                break;
            case 's':
                if (currentY < rows - 1 && map.at(currentY + 1).at(currentX)->getEntity() == nullptr &&
                    map.at(currentY + 1).at(currentX)->getRepresentation() != '#') {
                    hero->setY(currentY + 1);
                    if (map.at(currentY + 1).at(currentX)->getRepresentation() == '_') {
                        hero->setSpeed(hero->getSpeed()-0.2);
                    }
                }
                break;
            case 'd':
                if (currentX < cols - 1 && map.at(currentY).at(currentX + 1)->getEntity() == nullptr &&
                    map.at(currentY).at(currentX + 1)->getRepresentation() != '#') {
                    hero->setX(currentX + 1);
                    if (map.at(currentY).at(currentX + 1)->getRepresentation() == '_') {
                        hero->setSpeed(hero->getSpeed()-0.2);
                    }
                }
                break;
            default:
                break;
        }

        if (map.at(hero->getPosition().second).at(hero->getPosition().first)->getItem() != nullptr) {
            std::cout << "Do you want to take this item ? (y/n)" << std::endl;
            char choice;

            std::cin >> choice;
            if (choice == 'y') {
                hero->addItemToEquipment(
                        map.at(hero->getPosition().second).at(hero->getPosition().first)->getItem());
                map.at(hero->getPosition().second).at(hero->getPosition().first)->setItem(nullptr);
            }

        }
        map.at(hero->getPosition().second).at(hero->getPosition().first)->setEntity(hero);
        map.at(hero->getPosition().second).at(hero->getPosition().first)->setRepresentation(
                hero->getRepresentation());
    }
};

#endif //GAMEROGUELIKE_MAP_H