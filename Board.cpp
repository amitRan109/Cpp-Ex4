#include "Board.hpp"
#include <iostream>

using namespace std;

namespace WarGame {
    Soldier*& Board::operator[](std::pair<int,int> location) {
        return board[location.first][location.second];
    }
    Soldier*  Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
        int i=source.first;
        int j=source.second;
        if (i < 0 || j < 0) throw runtime_error("Err:move 1");
        if (i >= board[0].size() || j >= board.size()) throw runtime_error("Err:move 2");
        Soldier* sold = board[i][j];
        if (sold==nullptr) throw runtime_error("Err:move 3");
        if (sold->get_player()!=player_number)throw runtime_error("Err:move 4");
        switch (direction)
        {
        case Up:
            i++;
            if (i >= board[0].size() || board[i][j]) throw runtime_error("Err:move 5");
            board[i-1][j] = nullptr;
            board[i][j] = sold;
            break;
        case Down:
            i--;
            if (i < 0 || board[i][j]) throw runtime_error("Err:move 7");
            board[i+1][j] = nullptr;
            board[i][j] = sold;
            break;
        case Right:
            j++;
            if (j >= board.size() || board[i][j]) throw runtime_error("Err:move 10");
            board[i][j-1] = nullptr;
            board[i][j] = sold;
            break;
        case Left: 
            j--;
            if (j < 0 || board[i][j]) throw runtime_error("Err:move 12");
            board[i][j+1] = nullptr;
            board[i][j] = sold;
            break;
        }
        sold->act(board,{i,j});
        for (int i=0; i < board.size(); i++){
            for (int j=0; j < board[0].size(); j++){
                if (board[i][j] != nullptr && board[i][j]->get_heal() <=0) board[i][j] = nullptr;
            }
        }
    }
    bool Board::has_soldiers(uint player_number) const{
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                if (board[i][j]!=nullptr){
                    if (board[i][j]->get_player() ==player_number) 
                    return true;
                }
            }
        }
        return false;
    }

    void Board::print(){
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                Soldier* temp= board[i][j];
                if (temp == nullptr) cout<<"0"<<" ";
                else cout<<temp->get_player()<<"-"<<temp->get_type()<<" ";
            }
            cout << " " << endl;
        }
        cout << " " << endl;
    }
    
    Soldier* Board::max_health (uint player_number){
      int max_h = 0;
      Soldier* sold = nullptr;
      for (int i=0; i < board.size(); i++){
        for (int j=0; j < board[0].size(); j++){
            Soldier* temp = board[i][j];
            if (temp == nullptr || temp->get_player() != player_number)
                continue;

            if (temp->get_heal() > max_h){
                max_h = temp->get_heal();
                sold = temp;
            }
        }
      }
      return sold;
    }

    std::pair<int,int> Board:: get_loc (Soldier* s){
      for (int i=0; i < board.size(); i++){
        for (int j=0; j < board[0].size(); j++){
          if (board[i][j] == s) return {i,j};
        }
      }
      return {-1,-1};
    }

}