#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {

protected:
	const static unsigned int maxHitPoints = 10;
	const static unsigned int maxEnergyPoints = 10;
	const static unsigned int attackDamage = 0;

    std::string type;
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    ClapTrap() {};

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &ct);
    virtual ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &ct);

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

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

    std::string getName() const;
    unsigned int getDamage() const;
};

#endif