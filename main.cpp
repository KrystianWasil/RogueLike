#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Map.h"

int main() {
    int rows = 20;
    int cols = 20;

    Map map(rows, cols);
    map.InitMap();
    map.DisplayMap();

    return 0;
}

