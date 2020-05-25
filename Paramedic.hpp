#pragma once
#include "Soldier.hpp"
#include <vector>

class Paramedic : public virtual Soldier {
public:
    Paramedic (int p): Soldier(p,100,50,3) {}
    Paramedic (): Soldier(0,0,0,3) {}
    void act(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc);
};