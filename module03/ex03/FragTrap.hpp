#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

protected:
	const static unsigned int maxHitPoints = 100;
	const static unsigned int maxEnergyPoints = 100;
	const static unsigned int attackDamage = 30;
    FragTrap() : ClapTrap() {}

public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &ft);
    virtual ~FragTrap();
    FragTrap &operator=(const FragTrap &ft);

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    void highFivesGuys(void);

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