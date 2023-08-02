#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(const std::string &type) {
	this->type = type;
	std::cout << "AMateria default constructor called" << std::endl;	
}

AMateria::AMateria(const AMateria &a) {
	this->type = a.type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &a) {
	if (this == &a)
		return *this;
	this->type = a.type;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "AMateria's use function called... this should not happen..." << std::endl;
}


