#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
    ClapTrap() {};

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &ct);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &ct);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    unsigned int getDamage() const;
    void setDamage(unsigned int amount);
};

#endif