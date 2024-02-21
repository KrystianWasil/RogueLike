//
// Created by wasil on 05.12.2023.
//

#ifndef ROGUELIKE_ITEM_H
#define ROGUELIKE_ITEM_H

#include <memory>
#include <string>

class Item {
private:
    int x,y;
    char representation;
    double extraDamage;
    double extraArmor;
    double heal;
    double speed;
    double magicPower;

public:
    std::string id = "";

    Item(char representation, double extraDamage, double extraArmor, double heal, double speed, double magicPower,
         const std::string &id) : representation(representation), extraDamage(extraDamage), extraArmor(extraArmor),
                                  heal(heal), speed(speed), magicPower(magicPower), id(id) {}

    double getExtraDamage() const {
        return extraDamage;
    }

    void setExtraDamage(double extraDamage) {
        this->extraDamage = extraDamage;
    }

    double getExtraArmor() const {
        return extraArmor;
    }


    [[nodiscard]] int getX() const {
        return x;
    }

    void setX(int x) {
        Item::x = x;
    }

    [[nodiscard]] int getY() const {
        return y;
    }

    void setY(int y) {
        Item::y = y;
    }

    void setExtraArmor(double extraArmor) {
        this->extraArmor = extraArmor;
    }

    double getMagicPower() const {
        return magicPower;
    }

    void setMagicPower(double magicPower) {
        this->magicPower = magicPower;
    }

    double getHeal() const {
        return heal;
    }

    void setHeal(double heal) {
        this->heal = heal;
    }

    double getSpeed() const {
        return speed;
    }

    void setSpeed(double speed) {
        this->speed = speed;
    }

    char getRepresentation() const {
        return representation;
    }

    void setRepresentation(char representation) {
        this->representation = representation;
    }
};

using ItemPtr = std::shared_ptr<Item>;

#endif //ROGUELIKE_ITEM_H
