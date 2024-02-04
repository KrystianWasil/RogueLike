// FunctionFight.h

#ifndef ROGUELIKE_FUNCTIONFIGHT_H
#define ROGUELIKE_FUNCTIONFIGHT_H

#include <cstdlib>
#include <ctime>

bool DidYouHit(int chanceOfAttack, int chanceOfAvoid, int armor) {
    int doll = 1 + rand() % 20;
    if ((doll + chanceOfAttack - chanceOfAvoid) > armor ) {
        return true;
    }
    return false;
}


#endif //ROGUELIKE_FUNCTIONFIGHT_H
