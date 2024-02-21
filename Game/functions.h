//
// Created by Krystian Wasil on 01/02/2024.
//

#include <iostream>
#include "Entity.h"
#include "Game.h"
#include "Hero.h"
#include "Armor.h"

//bool flag_for_g = false;




void printStats(std::shared_ptr<Entity> h) {
    std::cout << "Yours HP: " << h->getHealth() << "Yours Speed: " <<h->getSpeed() << "Yours Physical Damage: "<< h->getPhysicalDamage() <<std::endl;
    std::cout << "Yours Magical Damage: " << h->getMagicalDamage() << "Yours Armor: " << h->getArmor() << "Yours kills :" << h->getKills() << std::endl;
    std::cout << "Level: " << h->getLevel() << std::endl;
}

void moveEnemy(Game& map,std::vector<std::shared_ptr<Entity>> enemies) {
    for (const auto & enemy : enemies) {
//        if (!flag_for_g) {
            map.Mob(enemy); //,flag_for_g
//        }
    }

}
void movePlayer(Game& map, std::shared_ptr<Hero> h, char direction) {
    if (h->isKey()) {
        map.GenerateDungeons(h->getLevel());
        h->setKey();
    }
    map.EntityMoving(direction, h);

    system("clear");
    map.DisplayMap();
    printStats(h);

}



void Equipment(std::shared_ptr<Hero> h, Game& map) {
    h->getEquipment();
    std::cout << "Type 'd' to drop or 'u' to use\n";
    std::string input;
    std::cin >> input;

    if (input == "q") {
        system("clear");
        map.DisplayMap();
        printStats(h);
    }
    else if (input == "d") {
        // Drop item
        int index;
        h->getEquipment();
        std::cout << "Enter the index of the item to drop: ";
        std::cin >> index;
        h->DropItem(index);
        std::cout << "You dropped item number: " << index << " Type 'q' to leave\n";
        char type2;
        std::cin >> type2;
        if (type2 == 'q') {
            map.DisplayMap();
            printStats(h);
        }
    }
    else if (input == "u") {
        // Use item
        int index;
        h->getEquipment();
        std::cout << "Enter the index of the item to use: ";
        std::cin >> index;
        h->useItem(index);
        std::cout << "You used item number: " << index << " Type 'q' to leave\n";
        char type2;
        std::cin >> type2;
        if (type2 == 'q') {
            map.DisplayMap();
            printStats(h);
        }
    }
}
