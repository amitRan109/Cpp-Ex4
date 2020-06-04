#pragma once
#include "Sniper.hpp"
#include <vector>
using namespace WarGame;
class SniperCommander : public Sniper {
public:
    SniperCommander (int p): Soldier(p,120,100,20) {}
    void act(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc);
    void act_all (std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc);
};
