#include "doctest.h"
#include "DemoGame.hpp"  

TEST_CASE("check all"){
    WarGame::DemoGame demoGame;
    for (int i=0; i<100; i++) {
        CHECK(demoGame.play()==0);
    }
}