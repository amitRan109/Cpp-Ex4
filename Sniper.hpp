#pragma once
#include "Soldier.hpp"
#include <vector>

class Sniper : public virtual Soldier {
    
public:
    Sniper (int p): Soldier(p,100,50,2) {}
    Sniper () : Soldier(0,0,0,2) {}
    void act(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc);
};
