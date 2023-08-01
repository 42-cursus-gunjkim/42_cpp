#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal() {
	this->type = c.type;
	std::cout << "Cat copy constructor called" << std::endl; 
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c) {
	this->type = c.type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Maybe Meow Sound..." << std::endl;
}

std::string Cat::getType() const {
	return this->type;
}
