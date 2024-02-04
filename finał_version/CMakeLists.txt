cmake_minimum_required(VERSION 3.26)
project(RogueLike)

set(CMAKE_CXX_STANDARD 17)

add_executable(RogueLike main.cpp
        Tile.cpp
        Tile.h
        Floor.cpp
        Floor.h
        Game.cpp
        Game.h
        Wall.cpp
        Wall.h
        Entity.cpp
        Entity.h
        Prisoner.cpp
        Prisoner.h
        Hero.cpp
        Hero.h
        TestFight.h
        FunctionFight.cpp
        FunctionFight.h
        Wall.h
        Item.cpp
        Item.h
        Item.h
        HungryDog.cpp
        HungryDog.h
        HungryDog.h
        OldWizard.cpp
        OldWizard.h
        OldWizard.h
        MutantBat.cpp
        MutantBat.h
        MutantBat.h
        Guard.cpp
        Guard.h
        Guard.h
        Shoes.cpp
        Shoes.h
        Shoes.h
        Armor.cpp
        Armor.h
        Armor.h
        Knife.cpp
        Knife.h
        PowerSpell.cpp
        PowerSpell.h
        Gun.cpp
        Gun.h
        Shield.cpp
        Shield.h
        Sword.cpp
        Sword.h
        Sword.h
        PowerSpell.h
        Potion.h
        ../ItemTypesEnum.h
        Stroller.h
        Stroller.cpp
        Door.h
        functions.h
        Key.h
)
add_subdirectory(Google_tests)

