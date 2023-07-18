#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
    std::string name;
    DiamondTrap() {};

public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &dt);
    ~DiamondTrap() {};
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif