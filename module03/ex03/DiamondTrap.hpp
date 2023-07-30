#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	const static unsigned int maxHitPoints = FragTrap::maxHitPoints;
	const static unsigned int maxEnergyPoints = ScavTrap::maxEnergyPoints;
	const static unsigned int attackDamage = FragTrap::attackDamage;

    std::string name;
    DiamondTrap() {};

public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &dt);
    ~DiamondTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
	virtual void whoAmI() {
		std::cout << "\n\n__________________________\n";
		std::cout << "I am " << this->name << " of type " << this->type << std::endl;
		std::cout << "My maxHitPoints is " << this->maxHitPoints << std::endl;
		std::cout << "My hitPoints is " << this->hitPoints << std::endl;
		std::cout << "My maxEnergyPoints is " << this->maxEnergyPoints << std::endl;
		std::cout << "My energyPoints is " << this->energyPoints << std::endl;
		std::cout << "My attackDamage is " << this->attackDamage << std::endl;
		std::cout << "__________________________\n\n";
	}
};

#endif