#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &b) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &b) {
	if (this == &b)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return *this;
}