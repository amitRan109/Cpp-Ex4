#pragma once
#include <stdexcept>
class Soldier {
    int gamer_num; //the gamer num
    std::pair<int,int> location; //the location of the soldier
    int health_points;
    int damage_per_activity; //damage of getting hurt

public:
    Soldier(int g,std::pair<int,int> l,int h,int d)
        :gamer_num(g),location(l),health_points(h),damage_per_activity(d){} 
    virtual void act () {};
    virtual void move (std::pair<int,int> loc){};
    // virtual void set_gamer (int new_gamer);
    // virtual int get_gamer ();
    // virtual void set_loc (std::pair<int,int> new_loc);
    // virtual std::pair<int,int> get_loc ();
    // virtual void set_heal (int new_heal);
    // virtual int get_heal ();
    // virtual void set_damag (int new_damag);
    // virtual int get_damag ();
};