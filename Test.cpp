#include "doctest.h"
#include <iostream>
//#include "DemoGame.hpp"  
#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;
using namespace std;
TEST_CASE("remove me"){
    for (int i=0; i <= 50; i++) CHECK(true);
}

TEST_CASE("5*5"){ //50
    Board board(5,5);
    //player 1
        CHECK(!board.has_soldiers(1));
        board[{0,0}] = new Sniper(1);
		board[{0,1}] = new FootSoldier(1);
		board[{0,2}] = new SniperCommander(1);
		board[{0,3}] = new FootCommander(1);
		board[{0,4}] = new Paramedic(1);
		CHECK(board.has_soldiers(1));

        //player 2
        CHECK(!board.has_soldiers(2));
        board[{4,0}] = new Sniper(2);
		board[{4,1}] = new FootSoldier(2);
		board[{4,2}] = new SniperCommander(2);
		board[{4,3}] = new FootCommander(2);
		board[{4,4}] = new Paramedic(2);
		CHECK(board.has_soldiers(2));

 board.print();
        CHECK_THROWS(board.move(1,{4,0},Board::MoveDIR::Up));//player wrong
        CHECK_THROWS(board.move(1,{0,0},Board::MoveDIR::Down));//out of board
        CHECK_THROWS(board.move(1,{1,0},Board::MoveDIR::Down));//no soldier
        CHECK_THROWS(board.move(2,{4,0},Board::MoveDIR::Down));//out of board
        CHECK_THROWS(board.move(2,{4,0},Board::MoveDIR::Right));//cant move

        CHECK_THROWS(board.move(2,{0,0},Board::MoveDIR::Right));//player wrong
        CHECK_THROWS(board.move(2,{0,3},Board::MoveDIR::Right));//player wrong
        CHECK_THROWS(board.move(2,{10,10},Board::MoveDIR::Right));//out of board
        CHECK_THROWS(board.move(2,{4,0},Board::MoveDIR::Down));//out of board
        CHECK_THROWS(board.move(2,{3,3},Board::MoveDIR::Right));//no soldier
        CHECK_THROWS(board.move(2,{4,3},Board::MoveDIR::Right));//cant move

        board.move(1,{0,0},Board::MoveDIR::Up); //sniper
        board.move(2,{4,1},Board::MoveDIR::Up); //foot
        board.move(1,{1,0},Board::MoveDIR::Up); //sniper
        board.move(2,{3,1},Board::MoveDIR::Right); //sniper
        board.move(1,{2,0},Board::MoveDIR::Up); //sniper, fc died

        CHECK_THROWS(board.move(1,{0,0},Board::MoveDIR::Up));//no soldier
        CHECK_THROWS(board.move(2,{3,0},Board::MoveDIR::Up));//wrong player
        CHECK_THROWS(board.move(2,{4,4},Board::MoveDIR::Right));//out
        CHECK_THROWS(board.move(1,{0,4},Board::MoveDIR::Left));//out
        CHECK_THROWS(board.move(1,{0,2},Board::MoveDIR::Left));//cant move

        board.move(2,{4,3},Board::MoveDIR::Up);
        board.move(1,{0,3},Board::MoveDIR::Up);
        board.move(2,{3,3},Board::MoveDIR::Right);
        board.move(1,{3,0},Board::MoveDIR::Left);
        board.move(2,{3,2},Board::MoveDIR::Up);

        CHECK_THROWS(board.move(1,{0,3},Board::MoveDIR::Up));//no soldier
        CHECK_THROWS(board.move(1,{4,4},Board::MoveDIR::Up));//wrong player
        CHECK_THROWS(board.move(2,{4,0},Board::MoveDIR::Left));//out
        CHECK_THROWS(board.move(2,{4,4},Board::MoveDIR::Right));//out
        CHECK_THROWS(board.move(1,{4,4},Board::MoveDIR::Up));//cant move
        CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Left));//cant move
        CHECK_THROWS(board.move(1,{0,2},Board::MoveDIR::Right));//cant move
        CHECK_THROWS(board.move(1,{4,0},Board::MoveDIR::Left));//wrong player
        CHECK_THROWS(board.move(2,{1,3},Board::MoveDIR::Left));//wrong player
        CHECK_THROWS(board.move(2,{3,1},Board::MoveDIR::Left));//wrong player

        board.move(1,{0,4},Board::MoveDIR::Right);
        board.move(2,{4,2},Board::MoveDIR::Up);
        board.move(1,{1,3},Board::MoveDIR::Up);
        board.move(2,{3,4},Board::MoveDIR::Left);
        board.move(2,{3,2},Board::MoveDIR::Down);

        CHECK_THROWS(board.move(1,{2,3},Board::MoveDIR::Up));//no soldier
        CHECK_THROWS(board.move(1,{2,2},Board::MoveDIR::Up));//wrong player
        CHECK_THROWS(board.move(2,{3,4},Board::MoveDIR::Right));//out
        CHECK_THROWS(board.move(2,{4,4},Board::MoveDIR::Right));//out
        CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Left));//cant move
        CHECK_THROWS(board.move(1,{0,2},Board::MoveDIR::Left));//cant move
        CHECK_THROWS(board.move(1,{3,4},Board::MoveDIR::Down));//cant move
        CHECK_THROWS(board.move(1,{2,2},Board::MoveDIR::Left));//wrong player
        CHECK_THROWS(board.move(2,{1,3},Board::MoveDIR::Left));//wrong player
        CHECK_THROWS(board.move(2,{3,1},Board::MoveDIR::Left));//wrong player

        board.move(2,{4,0},Board::MoveDIR::Right);
        board.move(1,{2,3},Board::MoveDIR::Left);
        board.move(2,{4,2},Board::MoveDIR::Up);
        board.move(1,{3,1},Board::MoveDIR::Right);
        board.move(2,{3,3},Board::MoveDIR::Up);

        CHECK_THROWS(board.move(2,{0,1},Board::MoveDIR::Down));//no soldier
        CHECK_THROWS(board.move(2,{3,0},Board::MoveDIR::Up));//wrong player
        CHECK_THROWS(board.move(2,{4,1},Board::MoveDIR::Down));//out
        CHECK_THROWS(board.move(1,{3,0},Board::MoveDIR::Right));//out
        CHECK_THROWS(board.move(2,{3,2},Board::MoveDIR::Up));//cant move
        CHECK_THROWS(board.move(2,{2,2},Board::MoveDIR::Down));//cant move
        CHECK_THROWS(board.move(2,{2,2},Board::MoveDIR::Right));//cant move
        CHECK_THROWS(board.move(1,{4,1},Board::MoveDIR::Left));//wrong player
        CHECK_THROWS(board.move(1,{3,2},Board::MoveDIR::Left));//wrong player
        CHECK_THROWS(board.move(2,{0,3},Board::MoveDIR::Left));//wrong player


}