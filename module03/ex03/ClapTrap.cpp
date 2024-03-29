#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(maxHitPoints), energyPoints(maxEnergyPoints), damage(attackDamage) {
    std::cout << "ClapTrap " << this->name << " constructed by ClapTrap(const std::string &name)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct) : name(ct.name), hitPoints(ct.hitPoints), energyPoints(ct.energyPoints), damage(attackDamage) {
    std::cout << "ClapTrap " << this->name << " constructed by ClapTrap(const ClapTrap &ct)" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
	if (this == &ct)
		return *this;

    std::cout << "claptrap assign operator called" << std::endl;
    this->name = ct.name;
    this->hitPoints = ct.hitPoints;
    this->energyPoints = ct.energyPoints;
	this->damage = ct.damage;

    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is died... can't attack..." << std::endl;
        return ;
    }
    if (this->energyPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "ClapTrap " << this->name << " has no energy... attack failed..." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is already died.... stop attacking..." << std::endl;
        return ;
    }
    if (this->hitPoints < amount)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " take damage " << amount << ", " << this->hitPoints << " remained" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is died... can't repair..." << std::endl;
        return ;
    }
    if (this->energyPoints == 0) {
         std::cout << "ClapTrap " << this->name << " has no energy... repair failed..." << std::endl;
         return ;
    }
    if (this->hitPoints != this->maxHitPoints) {
        std::cout << "ClapTrap " << this->name << " repaired " << amount << std::endl;
        if (this->hitPoints + amount > this->maxHitPoints)
            this->hitPoints = this->maxHitPoints;
        else
            this->hitPoints += amount;
        this->energyPoints--;
    } else {
        std::cout << "ClapTrap " << this->name << " has maxHitPoints" << std::endl;
    }
}

std::string ClapTrap::getName() const {
    return this->name;
}

unsigned int ClapTrap::getDamage() const {
    return this->damage;
}
