#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->maxHitPoints = 100;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap " << this->name << " is constructed by FragTrap(const std::string &name)" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(dynamic_cast<const FragTrap&>(ft)) {
    std::cout << "FragTrap " << this->name << " is constructed by FragTrap(const FragTrap &st)" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " is destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &st) {
    this->name = st.name;
    this->hitPoints = st.hitPoints;
    this->energyPoints = st.energyPoints;
    this->attackDamage = st.attackDamage;

    return *this;
}

void FragTrap::attack(const std::string &target) {
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is died... can't attack..." << std::endl;
        return ;
    }
    if (this->energyPoints > 0) {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "FragTrap " << this->name << " has no energy... attack failed..." << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is already died.... stop attacking..." << std::endl;
        return ;
    }
    if (this->hitPoints < amount)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
    std::cout << "FragTrap " << this->name << " take damage " << amount << ", " << this->hitPoints << " remained" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is died... can't repair..." << std::endl;
        return ;
    }
    if (this->energyPoints == 0) {
         std::cout << "FragTrap " << this->name << " has no energy... repair failed..." << std::endl;
         return ;
    }
    if (this->hitPoints != this->maxHitPoints) {
        std::cout << "FragTrap " << this->name << " repaired " << amount << std::endl;
        if (this->hitPoints + amount > this->maxHitPoints)
            this->hitPoints = this->maxHitPoints;
        else
            this->hitPoints += amount;
        this->energyPoints--;
    } else {
        std::cout << "FragTrap " << this->name << " has maxHitPoints" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is died... can't highfives..." << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "FragTrap " << this->name << " has no energy... highfive failed..." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->name << " is HighFive" << std::endl;
}

std::string FragTrap::getName() const {
    return this->name;
}

unsigned int FragTrap::getDamage() const {
    return this->attackDamage;
}
