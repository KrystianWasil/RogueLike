//
// Created by wasil on 28.11.2023.
//

#ifndef ROGUELIKE_TEST_H
#define ROGUELIKE_TEST_H


#include <gtest/gtest.h>
#include "../Hero.h"
#include "../Prisoner.h"
#include "../TestFight.h"


class test : public testing::Test {
protected:
    Hero *hero;
    Prisoner *prisoner;
    virtual void SetUp()
    {
       hero = new Hero();
       prisoner = new Prisoner();
    }

    virtual void TearDown() {
        delete hero;
        delete prisoner;
    }

};

TEST_F(test, SingleFightTest) {


    resultsOfSingleFight result = SingleFight(*prisoner, *hero);

    ASSERT_TRUE(result.winner == prisoner || result.winner == hero);
    ASSERT_GE(result.numbOfHits, 0);
}


#endif //ROGUELIKE_TEST_H
