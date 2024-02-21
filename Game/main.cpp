#include <iostream>
#include <memory>
#include <sstream>
#include "Hero.h"
#include "Prisoner.h"
#include "TestFight.h"
#include "Game.h"
#include "HungryDog.h"
#include "OldWizard.h"
#include "MutantBat.h"
#include "Guard.h"
#include "Sword.h"
#include "Knife.h"
#include <chrono>
#include <thread>
#include "functions.h"




int main() {
    Game game(32, 70);
    game.InitMap();
    game.AddElementToLevel(std::make_shared<Shoes>());
    game.AddElementToLevel(std::make_shared<Potion>());
    game.AddElementToLevel(std::make_shared<Shield>());

    auto g = std::make_shared<Guard>();
    auto p = std::make_shared<Prisoner>();
    auto o = std::make_shared<OldWizard>();
    game.AddMobsToLevel(g);
    game.AddMobsToLevel(p);
    game.AddMobsToLevel(o);

    auto h = std::make_shared<Hero>();
    game.SetHeroOnMap(h);

    game.GenerateDungeons(0);
    game.DisplayMap();
    printStats(h);


    char key;
    while (true) {
        std::cin >> key;

        switch (key) {
            case 'w':
            case 's':
            case 'a':
            case 'd':
                movePlayer(game,h,key);
                moveEnemy(game,game.getMobs());
                break;
            case 'q':
                return 0;
            case 'e':
                Equipment(h, game);
                break;
            default:
                break;
        }




        if (!h->isAlive()) {
            printStats(h);
            std::cout << "U lost ! ";
            return 0;
        }
    }
}

