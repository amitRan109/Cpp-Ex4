#include "Soldier.hpp"
using namespace std;

class Sniper : public virtual Soldier {
    
public:
    Sniper (int g): Soldier(g,{0,0},150,20) {}
    Sniper () : Soldier(0,{0,0},0,0) {}
    void act();
    void move(std::pair<int,int> loc);
};