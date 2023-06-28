#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : weapon(NULL) {}

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

HumanB::HumanB(const HumanB &h) : name(h.name), weapon(h.weapon){}

HumanB &HumanB::operator=(const HumanB &h) {
	this->name = h.name;
	this->weapon = h.weapon;
	return *this;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (this->weapon == NULL) {
		std::cout << this->name << " punch to enemy because " << this->name << " has no weapon..." << std::endl;
		return;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
