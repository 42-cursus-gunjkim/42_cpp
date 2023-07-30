#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
	this->name = name;
	this->hitPoints = FragTrap::maxHitPoints;
	this->energyPoints = ScavTrap::maxEnergyPoints;
	std::cout << "DiamondTrap " << this->name << " is constructed by DiamondTrap(const std::string &name)" << std::endl;
	whoAmI();
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dynamic_cast<const ClapTrap&>(dt)), ScavTrap(dynamic_cast<const ScavTrap&>(dt)), FragTrap(dynamic_cast<const FragTrap&>(dt)) {
	std::cout << "DiamondTrap " << this->name << " is constructed by DiamondTrap(const DiamondTrap &dt)" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " is destructed" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    FragTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ScavTrap::beRepaired(amount);
}
