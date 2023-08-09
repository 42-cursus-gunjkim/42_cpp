#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &d) : Animal() {
	this->type = d.type;
	this->brain = new Brain();
	*(this->brain) = *(d.brain);
	std::cout << "Dog copy constructor called" << std::endl; 
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &d) {
	if (this == &d)
		return (*this);
	this->type = d.type;
	*(this->brain) = *(d.brain);
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Maybe Barking Sound..." << std::endl;
}

void Dog::setIdea(int idx, const std::string &idea) {
	brain->setIdea(idx, idea);
}

const std::string &Dog::getIdea(int idx) const{
	return brain->getIdea(idx);
}