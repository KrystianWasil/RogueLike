//
// Created by wasil on 23.11.2023.
//

#include <queue>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "Entity.h"
#include "Prisoner.h"


struct resultsOfSingleFight {
    int numbOfHits;
    Entity *winner;
};

struct resultsOfFights {
   int e1Wins;
   int e2Wins;
   int arr[10000];
};



resultsOfSingleFight SingleFight(Entity& attacker, Entity& victim) {
    resultsOfSingleFight results;
    int numbHits = 0;

    while (attacker.isAlive() && victim.isAlive()) {
        numbHits += 1;
        attacker.attack(&victim);
        victim.attack(&attacker);
    }

    if (attacker.isAlive()) {
        results.numbOfHits = numbHits;
        results.winner = &attacker;
    } else if (victim.isAlive()) {
        results.numbOfHits = numbHits;
        results.winner = &victim;
    }
    attacker.setHealth(100);
    victim.setHealth(100);


    return results;
}

resultsOfFights FightStatistics(Entity &attacker, Entity &victim, int numbFights) {
    int attackerWins = 0;
    int victimWins = 0;
    resultsOfFights mainResult;
    resultsOfSingleFight results;
    int numberOfFightsSingleFight[10000];

    for (int i = 0; i < numbFights; ++i) {
        results = SingleFight(attacker, victim);
        if (results.winner == &attacker) {
            attackerWins += 1;
            numberOfFightsSingleFight[i] = results.numbOfHits;
        } else {
            victimWins += 1;
            numberOfFightsSingleFight[i] = results.numbOfHits;
        }
    }

    mainResult.e1Wins = attackerWins;
    mainResult.e2Wins = victimWins;
    std::copy(std::begin(numberOfFightsSingleFight), std::end(numberOfFightsSingleFight), mainResult.arr);

    return mainResult;
}


#ifndef ROGUELIKE_WALKA_H
#define ROGUELIKE_WALKA_H

#endif //ROGUELIKE_WALKA_H
