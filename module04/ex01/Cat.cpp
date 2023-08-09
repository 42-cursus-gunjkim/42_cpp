#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal() {
	this->type = c.type;
	this->brain = new Brain();
	*(this->brain) = *(c.brain);
	std::cout << "Cat copy constructor called" << std::endl; 
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c) {
	if (this == &c)
		return (*this);
	this->type = c.type;
	*(this->brain) = *(c.brain);
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Maybe Meow Sound..." << std::endl;
}

void Cat::setIdea(int idx, const std::string &idea) {
	brain->setIdea(idx, idea);
}

const std::string &Cat::getIdea(int idx) const {
	return brain->getIdea(idx);
}
