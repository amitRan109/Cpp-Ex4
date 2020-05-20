#include "Paramedic.hpp"
#include <vector>
class ParamedicCommander : public Paramedic {
    std::vector <std::vector<Soldier*>> soldiers;
public:
    ParamedicCommander (int g): Soldier(g,{0,0},200,100) {}
    void act();
    void act_all();
};