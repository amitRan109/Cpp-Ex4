#pragma once
#include "Soldier.hpp"
#include <vector>
using namespace WarGame;

class FootSoldier : public virtual Soldier {
public:
    FootSoldier (int p): Soldier(p,100,10,1) {}
    FootSoldier():Soldier(0,0,0,1){}
    void act(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc);
    double distance (std::pair<int,int> a,std::pair<int,int> b);
};
