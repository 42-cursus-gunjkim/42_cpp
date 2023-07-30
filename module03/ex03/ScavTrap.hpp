#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

protected:
	const static unsigned int maxHitPoints = 100;
	const static unsigned int maxEnergyPoints = 50;
	const static unsigned int attackDamage = 20;
    ScavTrap() {};
public:
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &st);
    virtual ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &st);

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    void guardGate();

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