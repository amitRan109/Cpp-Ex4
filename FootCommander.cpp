#include "FootCommander.hpp"
using namespace WarGame;
void FootCommander::act(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc) {
    FootSoldier::act(board,my_loc);
    act_all(board,my_loc );
}
void FootCommander::act_all(std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc){
    for (int i=0; i < board.size(); i++){
        for (int j=0; j < board[0].size(); j++){
            Soldier* temp = board[i][j];
            if (temp == nullptr) continue; 
            if (temp->get_player() == this->get_player()){
                if (temp->get_type() == this->get_type()-5){
                    temp->act(board,my_loc);
                }
            }
        }
    }
}
