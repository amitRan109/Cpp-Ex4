#include "Paramedic.hpp"
#include <iostream>
using namespace WarGame;
using namespace std;

void Paramedic::act (std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc) {
    int x = my_loc.first;
    int y = my_loc.second;
    int i = x-1;
    int j = y-1;
    if (i < 0) i =0;
    if (j < 0) j = 0;
    for ( ; i <= x+1 && i < board.size(); i++){
        for ( ; j <= y+1 && j < board[0].size(); j++){
            if (i < 0 || i > board[0].size() 
             || j < 0 || j > board.size()
             || i == x || j == y) continue;
            if (board[i][j] == nullptr) continue;
            if (board[i][j]->get_player() == this->get_player()) 
                board[i][j]->health();
        }
    }
}
