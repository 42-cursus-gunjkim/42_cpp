#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ScavTrap(dynamic_cast<const )

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    FragTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ScavTrap::beRepaired(amount);
}
