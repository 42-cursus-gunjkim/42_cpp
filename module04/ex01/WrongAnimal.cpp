#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;	
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa) {
	this->type = wa.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wa) {
	if (this == &wa)
		return *this;
	this->type = wa.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "Maybe Strange WrongAnimal Sounds....?" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
