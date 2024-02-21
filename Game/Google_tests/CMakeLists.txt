project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# adding the Google_Tests_run target
add_executable(Google_Tests_run
        test.cpp
        test.h
)

target_link_libraries(Google_Tests_run Tile.cpp
        Tile.h
        Floor.cpp
        Floor.h
        Map.cpp
        Map.h
        Obstacles.cpp
        Obstacles.h
        Wall.cpp
        Wall.h
        WoodenDoor.cpp
        WoodenDoor.h
        Entity.cpp
        Entity.h
        Prisoner.cpp
        Prisoner.h
        Hero.cpp
        Hero.h
        TestFight.h
        FunctionFight.cpp
        FunctionFight.h
        Obstacles.h
        Wall.h
        main.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)