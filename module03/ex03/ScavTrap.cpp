#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = maxHitPoints;
    this->energyPoints = maxEnergyPoints;
	this->damage = attackDamage;

    std::cout << "ScavTrap " << this->name << " is constructed by ScavTrap(const std::string &name)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st) {
    std::cout << "ScavTrap " << this->name << " is constructed by ScavTrap(const ScavTrap &st)" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " is destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
	if (this == &st)
		return *this;

    this->name = st.name;
    this->hitPoints = st.hitPoints;
    this->energyPoints = st.energyPoints;
	this->damage = st.damage;

    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " is died... can't attack..." << std::endl;
        return ;
    }
    if (this->energyPoints > 0) {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->name << " has no energy... attack failed..." << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " is already died.... stop attacking..." << std::endl;
        return ;
    }
    if (this->hitPoints < amount)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
    std::cout << "ScavTrap " << this->name << " take damage " << amount << ", " << this->hitPoints << " remained" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " is died... can't repair..." << std::endl;
        return ;
    }
    if (this->energyPoints == 0) {
         std::cout << "ScavTrap " << this->name << " has no energy... repair failed..." << std::endl;
         return ;
    }
    if (this->hitPoints != this->maxHitPoints) {
        std::cout << "ScavTrap " << this->name << " repaired " << amount << std::endl;
        if (this->hitPoints + amount > this->maxHitPoints)
            this->hitPoints = this->maxHitPoints;
        else
            this->hitPoints += amount;
        this->energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->name << " has maxHitPoints" << std::endl;
    }
}

void ScavTrap::guardGate() {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " is died... can't guard gate..." << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " has no energy... guard gate failed..." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode" << std::endl;
}

std::string ScavTrap::getName() const {
    return this->name;
}

unsigned int ScavTrap::getDamage() const {
    return this->damage;
}