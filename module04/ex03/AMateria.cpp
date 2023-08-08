#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(const std::string &type) {
	this->type = type;
	this->isEquip = UNEQUIP;
}

AMateria::AMateria(const AMateria &a) {
	this->type = a.type;
	this->isEquip = a.isEquip;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &a) {
	if (this == &a)
		return *this;
	this->type = a.type;
	this->isEquip = a.isEquip;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "AMateria's use function called to " << target.getName() <<  "... this should not happen..." << std::endl;
}

void AMateria::setStatusEquip(bool e) {
	this->isEquip = e;
}

bool AMateria::getStatusEquip() {
	return this->isEquip;
}
