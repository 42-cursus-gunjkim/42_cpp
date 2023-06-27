#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " is constructed by ClapTrap(const std::string &name)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct) : name(ct.name), hitPoints(ct.hitPoints), energyPoints(ct.energyPoints), attackDamage(ct.attackDamage) {
    std::cout << "ClapTrap " << this->name << " is constructed by ClapTrap(const ClapTrap &ct)" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
    std::cout << "operator = called" << std::endl;
    this->name = ct.name;
    this->hitPoints = ct.hitPoints;
    this->energyPoints = ct.energyPoints;
    this->attackDamage = ct.attackDamage;

    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is died... can't attack..." << std::endl;
        return ;
    }
    if (this->energyPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << this->name << " : No energy... attack failed..." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is already died.... stop attacking..." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " take damage " << amount << std::endl;
    if (this->hitPoints < amount)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is died... can't repair..." << std::endl;
        return ;
    }
    if (this->energyPoints > 0) {
        std::cout << "ClapTrap " << this->name << " repaired " << amount << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    } else {
        std::cout << this->name << " : No energy... repair failed..." << std::endl;
    }
}

std::string ClapTrap::getName() const {
    return this->name;
}

unsigned int ClapTrap::getDamage() const {
    return this->attackDamage;
}
