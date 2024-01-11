#include <iostream>
#include "Hero.h"
#include "Prisoner.h"
#include "TestFight.h"
#include "Map.h"
#include "WoodenDoor.h"
#include "WallOnMap.h"
#include "HungryDog.h"
#include "OldWizard.h"
#include "MutantBat.h"
#include "Guard.h"
#include "Sword.h"
#include "Knife.h"



int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Map map(20,50);
    map.InitMap();
    auto *element = new WoodenDoor;
    auto *element2 = new WallOnMap;
    Hero *h = new Hero;
    auto *p = new Prisoner;
    auto *d = new HungryDog;
    auto *w = new OldWizard;
    auto *m = new MutantBat;
    auto *g = new Guard;
    auto *sword = new Sword;
    auto *knife = new Knife;
    // resultsOfFights results = FightStatistics( *h, *w, 10000);
    //std::cout << "Wygrane bohatera: " <<  results.e1Wins << " " << "Wygrane przeciwnika: " << results.e2Wins << " " << " Maksymalna ilosc uderzen: " <<  *std::max_element(std::begin(results.arr), std::end(results.arr)) << " " << "Minimalna ilosc uderzen: " << *std::min_element(std::begin(results.arr), std::end(results.arr));
    map.AddActor(h,4,5);
    map.AddActor(w,7,5);
    map.AddElement(element,3,2);
    map.AddElement(element2,1,5);
    map.AddItem(sword,4,8);
    map.AddItem(knife,2,9);
    std::cout << std::endl;
    char key;
    h->addItemToEquipment(sword);
    while(true) {
        std::cin >> key;
        std::cin.ignore();
        if (key == 'm') {
            system("clear");
            map.DisplayMap();
            std::cout << std::endl;
        }



        if (key == 'q')
            break;
        if (key == 'e') {
            system("clear");
            std::cout << "Equipment : " << std::endl;
            h->getEquipment();
            std::cout << std::endl;
        }



    }

    delete h;
    delete p;
    delete d;
    delete w;
    delete m;
    delete g;
    delete element;
    delete element2;
    delete sword;
    delete knife;

    return 0;
}

