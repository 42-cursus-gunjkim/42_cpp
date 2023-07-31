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

	ClapTrap *test = &diamond;
	ClapTrap *test1 = new FragTrap("test1");
	test->attack("here");
	test1->attack(test->getName());
	test->takeDamage(test1->getDamage());
	test->beRepaired(3);

	clap.beRepaired(30);

	DiamondTrap another(diamond);
	
	delete test1;
	
    return 0;
}