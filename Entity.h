// Entity.h

#ifndef ROGUELIKE_ENTITY_H
#define ROGUELIKE_ENTITY_H

#include <iostream>
#include "FunctionFight.h"
#include "Item.h"
#include <cstdlib>
#include <ctime>
#include <utility>
#include <array>

class Entity {
private:
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
    std::vector<Item*> equipment;
    Item hand;

public:
//    Entity(char representation, const std::string &name, double health, int energy, double physicalDamage,
//           double magicalDamage, int order, double armor, int speed, int level, const std::array<Item, 6> &equipment,
//           const std::array<Item, 20> &bag) : representation(representation), name(name), health(health),
//                                              energy(energy), physical_damage(physicalDamage),
//                                              magical_damage(magicalDamage), order(order), armor(armor), speed(speed),
//                                              level(level), equipment(equipment), bag(bag) {}

    Entity(char representation, const std::string &name, double health, int energy, double physicalDamage,
           double magicalDamage, int order, double armor, int speed, int level,
            std::vector<Item*> equipment,  Item hand) : representation(representation), name(name),
                                                                health(health), energy(energy),
                                                                physical_damage(physicalDamage),
                                                                magical_damage(magicalDamage), order(order),
                                                                armor(armor), speed(speed), level(level),
                                                                equipment(equipment), hand(hand) {}

    const std::string &getName() const {
        return name;
    }

    char getRepresentation() const {
        return representation;
    }

    int getOrder() {
        return order;
    }

    bool isAlive() {
        if (health > 0) {
            return true;
        }
        return false;
    }

    void setOrder(int order) {
        Entity::order = order;
    }

    double givenDamage() const {
        if (magical_damage != 0) {
            return magical_damage + physical_damage;
        } else
            return physical_damage;
    }

    double blockedDamage() const {
        return armor;
    }

    void getDamage(double givenDamageFromEnemy) {
       this->health -= givenDamageFromEnemy;
    }





    void attack(Entity *victim) {
        double givenDamageToEnemy = 0;
        if (DidYouHit(this->chanceOfAttack(), victim->chanceOfAvoid(), victim->armor)) {
             givenDamageToEnemy = (this->givenDamage() - victim->blockedDamage());
             if (givenDamageToEnemy < 0) {
                 givenDamageToEnemy = 1;
             }
            this->energy -=3;
        } else {
            this->energy +=1;
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
            std::cout << i << " Element: " << equipment[i]->id;
        }
    }
}

    void addItemToEquipment(Item *item) {
        if (this->equipment.size() < 10 ) {
            equipment.push_back(item);
        }
    }

    void showHand() {
    if (hand.id != "")
        std::cout << " Hand : " << hand.id;
    else std::cout << "The hand is empty";
    }
    void deleteHand() {
        hand.id = "";
    }
    void setHand(Item item) {
        this->hand = item;
        this->hand.id = item.id;
        if (item.id == "Armor") {
            this->armor += item.getExtraArmor();
        }
        else if (item.id == "Sword") {
            this->physical_damage += item.getExtraDamage();
            this->speed += item.getSpeed();
            this->magical_damage += item.getMagicPower();
        }
        else if (item.id == "Gun") {
            this->physical_damage += item.getExtraDamage();
        }
        else if (item.id == "Knife") {
            this->physical_damage +=item.getExtraDamage();
            this->speed += item.getSpeed();
        }
        else if (item.id == "Shield") {
            this->health += item.getHeal();
            this->armor += item.getExtraArmor();
        }
        else if (item.id == "Shoes") {
            this->speed += item.getSpeed();
        }
        else if (item.id == "PowerShell") {
            this->magical_damage += item.getMagicPower();
        }

    }


};

#endif //ROGUELIKE_ENTITY_H
