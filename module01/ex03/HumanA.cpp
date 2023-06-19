#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

HumanA::HumanA(const HumanA &h) : name(h.name), weapon(h.weapon) {}

HumanA &HumanA::operator=(const HumanA &h) {
	this->name = h.name;
	this->weapon = h.weapon;
	return *this;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
