#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) {
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB() {}

HumanB::HumanB(const HumanB &h) : name(h.name), weapon(h.weapon){}

HumanB &HumanB::operator=(HumanB &h) {
	this->name = h.name;
	this->weapon = h.weapon;
	return *this;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
