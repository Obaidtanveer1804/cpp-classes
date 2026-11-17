#include "player.h"

    // int hp_if_healed(Player p, int h);
    // void rest(Player& p);
    // const void show_status(const Player& p);
    
    // interface, what we can do  with the players etc
    void Player::take_damage(int amount )
    {
        hp -= amount;
        //  hp = hp - amoount
        if (hp < 0 ) 
        {
            hp = 0;
        } // no negative hp
    } 
    void Player::heal(int amount)
    {
        hp += amount; 
        if (hp > max_hp)
        {
            hp = 100;
        }
    } 

    void Player::print() const 
    {
        std::cout <<name <<" "<< hp << "\n";
    }

    bool Player::alive() const
    {
        return hp > 0;
    }

    void Player::take_damage(int damage, int armor)
    {
        int through = damage - armor;
        if(through < 0 )
        {
            through = 0;
        }
        take_damage(through);
    }

    bool Player::read(std::istream& is)
    {
        return  static_cast<bool>(is >> name >> hp);
    }

    void Player::print(std::ostream& os) const
    {
        os << name << " " << hp  << " \n";
    }

