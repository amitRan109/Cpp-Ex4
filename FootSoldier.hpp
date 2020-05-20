#pragma once
#include "Soldier.hpp"
class FootSoldier : public virtual Soldier {
public:
    FootSoldier (int g): Soldier(g,{0,0},100,10) {}
    FootSoldier():Soldier(0,{0,0},0,0){}
    void act();
    void move(std::pair<int,int> loc);
};