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
    virtual ~DiamondTrap();
    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
	void whoAmI();

	virtual std::string getName() const;
    virtual unsigned int getDamage() const;
};

#endif