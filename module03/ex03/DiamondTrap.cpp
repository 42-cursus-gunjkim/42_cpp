#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->hitPoints = maxHitPoints;
	this->energyPoints = maxEnergyPoints;
	this->damage = attackDamage;
	std::cout << "DiamondTrap " << this->name << " is constructed by DiamondTrap(const std::string &name)" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dt), ScavTrap(dt), FragTrap(dt) {
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

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->name << " , also Another name is " << ClapTrap::name << "." << std::endl;
}

std::string DiamondTrap::getName() const {
    return this->name;
}

unsigned int DiamondTrap::getDamage() const {
    return this->damage;
}
