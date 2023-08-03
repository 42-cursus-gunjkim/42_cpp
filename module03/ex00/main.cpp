#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap nick("Nick");
    ClapTrap john("John");
    ClapTrap nick_copy(nick);

    for (int i = 0; i < 11; i++) {
        nick.attack(john.getName());
        john.takeDamage(nick.getDamage());
        john.beRepaired(1);
    }

    nick_copy.attack(nick.getName());
    john = nick;


    return 0;
}