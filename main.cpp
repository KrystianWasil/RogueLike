#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Person.h"
#include "Obstacles.h"
#include "Items.h"


void DisplayMap(char map[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
            std::cout << map[i][j];
        std::cout << std::endl;
    }
}


void InitMap(char map[20][20]) {
    srand(time(nullptr));
    Obstacles o;
    Items item;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++) {
            int number = rand() % 20;
            if ((i == 0 || i == 19) || (j == 0 || j == 19)) {
                map[i][j] = '#';
            }
            else if (j > 0 && i > 0){
                if (number < 16 || (i == 1 && j == 1))
                    map[i][j] = '.';
                else if ((number == 17 || number == 19)) {
                    map[i][j] =  o.bush;
                }
                else if ((number == 16 || number == 18))
                    map[i][j] = item.health;
            }
        }


}

void MovePlayer(Person &hero, char map[20][20], char key, int &x, int &y) {

    switch(key) {
        case 'w':
            if (map[x-1][y] != '#'){
                map[x][y] = '.';
                x = x - 1;
            }
            break;
        case 's':
            if (map[x + 1][y] != '#'){
                map[x][y] = '.';
                x = x + 1;
            }
            break;
        case 'a':
            if (map[x][y - 1] != '#'){
                map[x][y] = '.';
                y = y - 1;
            }
            break;
        case 'd':
            if (map[x][y + 1] != '#'){
                map[x][y] = '.';
                y = y + 1;
            }
            break;
        default:
            break;
    }
    map[x][y] = hero.character;
#ifdef _WIN32
    system("cls"); // Wyczyszczenie konsoli w systemie Windows
#else
    system("clear"); // Wyczyszczenie konsoli w innych systemach
#endif

    DisplayMap(map);
}



int main() {
    Person hero;
    char map[20][20];
    InitMap(map);
    DisplayMap(map);

    char key;
    while (true) {
        std::cin >> key;
        if (key == 'q') {
            break;
        }
        MovePlayer(hero, map, key, hero.x, hero.y);

    }

   return 0;
}