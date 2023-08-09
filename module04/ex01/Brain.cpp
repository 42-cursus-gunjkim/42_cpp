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

void Brain::setIdea(int idx, const std::string &idea) {
	if (idx < 0 || idx >= 100) {
		std::cout << "wrong index... idx is between 0 and 100" << std::endl;
		return;
	}
	this->ideas[idx] = idea;
}

const std::string &Brain::getIdea(int idx) const {
	if (idx < 0 || idx >= 100) {
		std::cout << "wrong index... idx is between 0 and 100" << std::endl;
		return this->ideas[0];
	}
	return this->ideas[idx];
}