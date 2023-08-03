#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap nick("Nick");
    ScavTrap john("John");

    for (int i = 0; i < 11; i++) {
        john.attack(nick.getName());
        nick.takeDamage(john.getDamage());
        nick.beRepaired(1);
    }

    john.attack(nick.getName());
    nick.takeDamage(john.getDamage());
    john.guardGate();
    
    return 0;
}