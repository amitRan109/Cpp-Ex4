#include "Sniper.hpp"

void Sniper::act (std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc) {
    int max_health=0;
    Soldier* target= nullptr;
    for (int i=0; i < board.size(); i++){
        for (int j=0; j < board[0].size(); j++){
            if (board[i][j] == nullptr) continue;
            if (board[i][j]->get_player() != this->get_player()){
                if (board[i][j]->get_heal() > max_health){
                    max_health = board[i][j]->get_heal();
                    target = board[i][j];
                }
            }

        }
    }
    target->set_heal(this->get_damag());
}
