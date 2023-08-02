#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : name(name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character " << this->name << " created by Character default constructor" << std::endl;	
}

Character::Character(const Character &c) {
	this->name = c.name;
	for (int i = 0; i < 4; i++) {
		if (c.inventory[i])
			this->inventory[i] = c.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	std::cout << "Character " << this->name << " created by Character copy constructor" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "Character " << this->name << " destroyed by Character destructor" << std::endl;
}

Character &Character::operator=(const Character &c) {
	if (this == &c)
		return *this;
	this->name = c.name;
	for (int i = 0; i < 4; i++) {
		delete this->inventory[i];
		this->inventory[i] = NULL;
		if (c.inventory[i])
			this->inventory[i] = c.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}

