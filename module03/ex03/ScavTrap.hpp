#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

protected:
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
};

#endif