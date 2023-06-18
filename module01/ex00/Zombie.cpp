#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << this->name << " is dead" << std::endl;
}

Zombie::Zombie(Zombie &z) {
	this->name = z.name;
}

Zombie &Zombie::operator=(Zombie &z) {
	this->name = z.name;
	return *this;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}