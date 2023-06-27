#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << "ScavTrap " << this->name << " is constructed by ScavTrap(const std::string &name)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(dynamic_cast<const ClapTrap&>(st)) {
    std::cout << "ScavTrap " << this->name << " is constructed by ScavTrap(const ScavTrap &st)" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " is destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
    this->name = st.name;
    this->hitPoints = st.hitPoints;
    this->energyPoints = st.energyPoints;
    this->attackDamage = st.attackDamage;

    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode" << std::endl;
}
