#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &d) : Animal() {
	this->type = d.type;
	std::cout << "Dog copy constructor called" << std::endl; 
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &d) {
	this->type = d.type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Maybe Barking Sound..." << std::endl;
}

std::string Dog::getType() const {
	return this->type;
}