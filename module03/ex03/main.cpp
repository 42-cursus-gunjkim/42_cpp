#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");
	FragTrap frag("Frag");
	DiamondTrap diamond("Diamond");

	diamond.whoAmI();

	diamond.attack("Clap");
	clap.takeDamage(diamond.getDamage());
	
    return 0;
}