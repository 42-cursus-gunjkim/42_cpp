#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
    ClapTrap() {};

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &ct);
    virtual ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &ct);

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    std::string getName() const;
    unsigned int getDamage() const;
};

#endif