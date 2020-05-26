#include "FootSoldier.hpp"
#include <limits>
#include <cmath>
using namespace WarGame;

void FootSoldier::act (std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc ) {
    double min_dis = std::numeric_limits<double>::max();
    Soldier* target = nullptr;
    for (int i=0; i<board.size(); i++){
        for (int j=0; j<board[0].size(); j++){
            if (board[i][j] == nullptr) continue;
            if (board[i][j]->get_player() != this->get_player()){
                double dis = distance(my_loc,{i,j});
                if (dis < min_dis) {
                    min_dis = dis;
                    target = board[i][j];
                }
            }
        }
    }
    target->set_heal(this->get_damag());
}
double FootSoldier::distance (std::pair<int,int> a,std::pair<int,int> b){
    int x1 = a.first; int y1 = a.second;
    int x2 = b.first; int y2 = b.second;
    int ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return sqrt((double)ans);
}
