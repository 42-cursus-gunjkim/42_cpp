#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << this->name << " is dead" << std::endl;
}

Zombie::Zombie(const Zombie &z) {
	this->name = z.name;
}

Zombie &Zombie::operator=(const Zombie &z) {
	this->name = z.name;
	return *this;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	this->name = name;
}