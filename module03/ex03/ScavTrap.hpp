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

	virtual std::string getName() const;
    virtual unsigned int getDamage() const;
};

#endif