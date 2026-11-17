#pragma once
#include <iostream>
#include <string>

class Player{
    public:
    // state : what tha player has
    std::string name;
    int hp;
    int power;
    static constexpr int max_hp = 100; 

    void take_damage(int amount );
    void heal(int amount);
    void print() const;
    bool alive() const; 

    void take_damage(int damage, int armor); 
    bool read(std::istream& is);
    void print(std::ostream& os) const;

};