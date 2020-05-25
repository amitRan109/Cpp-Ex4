#include "Paramedic.hpp"
void Paramedic::act (std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc) {
    int x = my_loc.first;
    int y = my_loc.second;

    for (int i = x-1; i <= x+1; i++){
        for (int j = y-1; j <= y+1; j++){
            if (i < 0 || i > board[0].size() 
             || j < 0 || j > board.size()
             || i == x || j == y) continue;
            if (board[i][j] == nullptr) continue;
            if (board[i][j]->get_player() == this->get_player()) 
                board[i][j]->health();
        }
    }
}
