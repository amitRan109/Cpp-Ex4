#pragma once
#include "FootSoldier.hpp"
#include <vector>
using namespace WarGame;

class FootCommander : public FootSoldier {
public:
    FootCommander (int p): Soldier(p,150,20,10) {}
    void act(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc);
    void act_all(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc);
};

