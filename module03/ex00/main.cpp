#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap nick("Nick");
    ClapTrap john("John");

    for (int i = 0; i < 11; i++) {
        nick.attack(john.getName());
        john.takeDamage(nick.getDamage());
        john.beRepaired(1);
    }

    return 0;
}