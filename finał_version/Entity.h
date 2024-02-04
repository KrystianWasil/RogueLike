// Entity.h

#ifndef ROGUELIKE_ENTITY_H
#define ROGUELIKE_ENTITY_H

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "FunctionFight.h"
#include "Item.h"




class Entity {
private:
    int x, y; // coordynaty kazdej postaci na mapie
    char representation = 'x';
    std::string name;
    double health;
    int energy;
    double physical_damage;
    double magical_damage;
    int order;
    double armor;
    double speed;
    int level;
    std::vector<std::shared_ptr<Item>> equipment;
    int kills = 0;
    bool key  = false;

public:
    Entity(int x, int y, char representation, std::string name, double health, int energy, double physicalDamage,
           double magicalDamage, int order, double armor, double speed, int level,
           const std::vector<std::shared_ptr<Item>> &equipment) : x(x), y(y), representation(representation),
                                                                  name(std::move(name)), health(health), energy(energy),
                                                                  physical_damage(physicalDamage),
                                                                  magical_damage(magicalDamage), order(order),
                                                                  armor(armor), speed(speed), level(level),
                                                                  equipment(equipment) {}

    const std::string &getName() const {
        return name;
    }

    char getRepresentation() const {
        return representation;
    }

    void addKills() {
        this->kills+=1;
    }

    double getPhysicalDamage() const {
        return physical_damage;
    }

    double getMagicalDamage() const {
        return magical_damage;
    }

    double getSpeed() const {
        return speed;
    }

    int getLevel() const {
        return level;
    }

    int getKills() const {
        return kills;
    }

    int getOrder() const {
        return order;
    }

    bool isAlive() const {
        return (health > 0);
    }

    void setOrder(int order) {
        Entity::order = order;
    }

    double givenDamage() const {
        return (magical_damage != 0) ? (magical_damage + physical_damage) : physical_damage;
    }

    double blockedDamage() const {
        return armor;
    }

    void getDamage(double givenDamageFromEnemy) {
        health -= givenDamageFromEnemy;
    }

    void setSpeed(double speed) {
        Entity::speed = speed;
    }

    void attack(std::shared_ptr<Entity> victim) {
        double givenDamageToEnemy = 0;
        if (DidYouHit(this->chanceOfAttack(), victim->chanceOfAvoid(), victim->armor)) {
            givenDamageToEnemy = (this->givenDamage() - victim->blockedDamage());
            if (givenDamageToEnemy < 0) {
                givenDamageToEnemy = 1;
            }
            this->energy -= 2;
        } else {
            this->energy += 7;
        }
        victim->getDamage(givenDamageToEnemy);
    }

    int chanceOfAvoid() const {
        return speed + level;
    }

    int chanceOfAttack() const {
        return level + energy + speed;
    }

    int getHealth() const {
        return health;
    }

    int getEnergy() const {
        return energy;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    double getArmor() const {
        return armor;
    }

    void setHealth(double health) {
        this->health = health;
    }

    void getEquipment() {
        if (equipment.size() == 0)
            std::cout << "Equipment is empty";
        else {
            for (int i = 0; i < equipment.size(); ++i) {
                std::cout << i  << ":"<< " Element: " << equipment[i]->id << "\n";
            }
        }
    }

    void useItem(int index) {
        std::shared_ptr<Item> item = equipment[index];
        equipment.erase(equipment.begin() + index);
        if (item->getRepresentation() == 'M'){
            setHealth(item->getHeal());
            armor+=item->getExtraArmor();
        }
        else if (item->getRepresentation() == '<') {
            physical_damage+=item->getExtraDamage();
        }
        else if (item->getRepresentation() =='k') {
            physical_damage+= item->getExtraDamage();
            speed += item->getSpeed();
        }
        else if (item->getRepresentation() == 'h') {
            health+= item->getHeal();
            speed += item->getSpeed();
        }
        else if (item->getRepresentation() == 'o') {
            magical_damage += item->getMagicPower();
        }
        else if (item->getRepresentation() == 'O') {
            health += item->getHeal();
            armor += item->getExtraArmor();
        }
        else if (item->getRepresentation() == 'l') {
            speed += item->getSpeed();
        }
        else if (item->getRepresentation() == '!') {
            physical_damage += item->getExtraDamage();
            magical_damage += item->getMagicPower();
            speed += item->getSpeed();
        }
        else if (item->getRepresentation() == '?') {
            health += item->getHeal();
            level+= 1;
            key = true;
        }
    }

    bool isKey() const {
        return key;
    }

    void setKey() {
        this->key = false;
    }

    void addItemToEquipment(std::shared_ptr<Item> item) {

        if (item != nullptr) {
            if (equipment.size() < 10) {
                equipment.push_back(item);
                std::cout << "Item added to equipment and your stats are improved\n";

            } else {
                std::cout << "Equipment is full\n";
            }
        } else {
            std::cout << "Invalid item pointer\n";
        }

    }

    void DropItem(int index) {
        equipment.erase(equipment.begin() + index);
    }

    [[nodiscard]] std::pair<int, int> getPosition() const {
        return {this->x, this->y};
    }

    void setX(int x) {
        Entity::x = x;
    }

    void setY(int y) {
        Entity::y = y;
    }
};

using EntityPtr = std::shared_ptr<Entity>;

#endif //ROGUELIKE_ENTITY_H
