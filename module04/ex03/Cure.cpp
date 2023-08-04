#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &c) : AMateria(c) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &c) {
	if (this == &c)
		return *this;
	this->type = c.type;
	this->isEquip = c.isEquip;
	return *this;
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}