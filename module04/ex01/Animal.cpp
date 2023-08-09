#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;	
}

Animal::Animal(const Animal &a) {
	this->type = a.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &a) {
	if (this == &a)
		return *this;
	this->type = a.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Maybe Strange Animal Sounds....?" << std::endl;
}

const std::string &Animal::getType() const {
	return this->type;
}