#include "player.h"
#include <iostream>
#include <string>


int hp_if_healed(Player p, int h)
{
    p.heal(h);
    return p.hp;
}

void rest(Player& p)
{
    p.heal(2);
}

const void show_status(const Player& p)
{
    std::cout << (p.alive() ? 1 : 0) << "\n";
    p.print();
}

int main(){

    Player hero{"obaid",80};
    Player hero2{"dim", 100};

    hero.print();
    hero2.print();

    hero.take_damage(500);
    hero2.take_damage(500);

    hero.print();
    hero2.print();  

    hero.heal(500);
    hero2.heal(500);

    hero.print();
    hero2.print();  

    std::cout << "-----------------------------" << "\n";
    std::cout << "hero alive?" << hero.alive() << " \n";

    hero.power = 25;
    hero2.power = 10;
    int round = 1;

    while (hero2.alive() && hero.alive())
    {
        std::cout << "BATTLE    " << " \n";
        hero.take_damage(hero2.power);
        if(hero.alive())
        {
            hero2.take_damage(hero.power);
        }
        round++;
        std::cout << "round " << round << " " << hero.name << " " << hero.hp 
                  << " vs   " << " " << hero2.name << " " << hero2.hp << " \n";
    }

    std::cout << "winner " << (hero.alive() ? hero.name : hero2.name) << " \n";
    std::cout << "-----------------------------" << "\n";

    hero.heal(30);
    hero2.heal(30);

    hero.print();
    hero2.print();  

    hero.take_damage(20, 100);
    hero2.take_damage(20, 100);

    hero.print();
    hero2.print();  

    hero.take_damage(20);
    hero.take_damage(100, 20);
    hero2.take_damage(100, 20);

    hero.heal(100);
    hero2.heal(100);

    hero.print();
    hero2.print(std::cout);

    Player* target = &hero;
    target->take_damage(24);
    (*target).print();
    hero2.print();

    target = &hero2;
    target->take_damage(22);
    target->print();

    // look into this, why does this say this (error: aggregate ‘std::ostringstream outt’ has incomplete type and cannot be defined
    // 67 |     std::ostringstream outt;)
    // std::ostringstream outt;
    // hero.print(outt);            

    std::cout << "-----------------------------" << "\n";

    std::cout << "hp if healed " <<  hp_if_healed(hero2, 2) <<"\n";
    hero2.print();
    rest(hero2);
    hero2.print();
    show_status(hero2);

    return 0;
}
