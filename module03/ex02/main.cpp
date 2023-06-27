#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    ClapTrap nick("Nick");
    ScavTrap john("John");
    FragTrap david("david");

    for (int i = 0; i < 11; i++) {
        nick.attack(john.getName());
        john.takeDamage(nick.getDamage());
        john.beRepaired(1);
    }

    john.attack(nick.getName());
    nick.takeDamage(john.getDamage());
    john.guardGate();
    david.attack(nick.getName());
    nick.takeDamage(david.getDamage());
    david.highFivesGuys();
    
    return 0;
}