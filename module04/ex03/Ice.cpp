#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &i) : AMateria(i) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &i) {
	if (this == &i)
		return *this;
	this->type = i.type;
	this->isEquip = i.isEquip;
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
