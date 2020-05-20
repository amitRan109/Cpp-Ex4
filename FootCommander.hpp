#include "FootSoldier.hpp"
#include <vector>
class FootCommander : public FootSoldier {
    std::vector <std::vector<Soldier*>> soldiers;
public:
    FootCommander (int g): Soldier(g,{0,0},150,20) {}
    void act();
    void act_all();
};
