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
	
	std::cout << std::endl << "------------copy constructor-----------" << std::endl;
	DiamondTrap another(diamond);
	another.whoAmI();

	std::cout << std::endl << "------------operator =-----------" << std::endl;
	DiamondTrap david("david");
	david.whoAmI();
	david = another;
	david.whoAmI();
	diamond.attack("david");
	david.takeDamage(diamond.getDamage());
	david.whoAmI();
	diamond.attack("david");
	david.takeDamage(diamond.getDamage());
	david.whoAmI();
	diamond.attack("david");
	david.takeDamage(diamond.getDamage());
	david.whoAmI();
	diamond.attack("david");
	david.takeDamage(diamond.getDamage());
	david.whoAmI();

    return 0;
}