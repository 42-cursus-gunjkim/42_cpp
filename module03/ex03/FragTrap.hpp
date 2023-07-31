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

    void highFivesGuys();

	virtual std::string getName() const;
    virtual unsigned int getDamage() const;
};

#endif