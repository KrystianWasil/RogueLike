//
// Created by wasil on 05.12.2023.
//

#ifndef ROGUELIKE_ITEM_H
#define ROGUELIKE_ITEM_H


#include <string>

class Item {
private:
    char representation;
    double extraDamage;
    double extraArmor;
    double heal;
    double speed;
    double magicPower;
public:
    Item() {}
    std::string id;

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

    void setExtraArmor(double extraArmor) {
        this->extraArmor = extraArmor;
    }

    double getMagicPower() const {
        return magicPower;
    }

    void setMagicPower(double magicPower) {
        Item::magicPower = magicPower;
    }

    double getHeal() const {
        return heal;
    }

    void setHeal(double heal) {
        Item::heal = heal;
    }

    double getSpeed() const {
        return speed;
    }

    void setSpeed(double speed) {
        Item::speed = speed;
    }

    char getRepresentation() const {
        return representation;
    }

    void setRepresentation(char representation) {
        Item::representation = representation;
    }

};


#endif //ROGUELIKE_ITEM_H
