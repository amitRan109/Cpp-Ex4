#include "Soldier.hpp"
class Paramedic : public virtual Soldier {
public:
    Paramedic (int g): Soldier(g,{0,0},150,20) {}
    Paramedic (): Soldier(0,{0,0},0,0) {}
    void act();
    void move(std::pair<int,int> loc);
};