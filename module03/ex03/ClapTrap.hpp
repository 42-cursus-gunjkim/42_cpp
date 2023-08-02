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
	unsigned int damage;
    ClapTrap() {};

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &ct);
    virtual ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &ct);

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    virtual std::string getName() const;
    virtual unsigned int getDamage() const;
};

#endif