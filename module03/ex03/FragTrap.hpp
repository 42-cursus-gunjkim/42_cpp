#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.cpp"

class FragTrap : public ClapTrap {
private:
    FragTrap() : ClapTrap() {}

public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &ft);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &ft);

    void highFivesGuys(void);
};

#endif