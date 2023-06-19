#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type) {}

Weapon::~Weapon() {}

Weapon::Weapon(const Weapon &w) {
	this->type = w.type;
}

Weapon &Weapon::operator=(const Weapon &w) {
	this->type = w.type;
	return *this;
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}

const std::string &Weapon::getType() const {
	return this->type;
}