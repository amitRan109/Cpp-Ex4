#pragma once
#include <stdexcept>
#include <vector>
class Soldier {
    const int player_num; //the gamer num
    int health_points;
    const int max_health;
    const int damage_per_activity; //damage of getting hurt
    const int type; 
    //1-foot 15-footCommander 2-sniper 25-sniperCommander 
    //3-paramedic 35-paramedicCommander

public:
    Soldier(int p,int h,int d,int t)
        :player_num(p),health_points(h),damage_per_activity(d),max_health(h),type(t){} 
    virtual void act (std::vector <std::vector<Soldier*>> board,std::pair<int,int> my_loc) {};
    void health () {health_points = max_health;}
    int get_player (){return player_num;}
    int get_type () {return type;}
    void set_heal (int damage){health_points-=damage;}
    int get_heal () {return health_points;}
    int get_damag (){return this->damage_per_activity;}
    virtual ~Soldier(){}
};