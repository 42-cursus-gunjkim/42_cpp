#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ClapTrap nick("Nick");
    ScavTrap john("John");

    for (int i = 0; i < 11; i++) {
        nick.attack(john.getName());
        john.takeDamage(nick.getDamage());
        john.beRepaired(1);
    }

    john.attack(nick.getName());
    nick.takeDamage(john.getDamage());
    
    return 0;
}