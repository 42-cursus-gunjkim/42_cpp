#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc) : WrongAnimal() {
	this->type = wc.type;
	std::cout << "WrongCat copy constructor called" << std::endl; 
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wc) {
	if (this == &wc)
		return (*this);
	this->type = wc.type;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "Maybe Wrong Meow Sound..." << std::endl;
}

std::string WrongCat::getType() const {
	return this->type;
}
