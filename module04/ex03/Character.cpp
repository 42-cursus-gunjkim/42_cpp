#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : name(name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &c) {
	this->name = c.name;

	// deep copy
	for (int i = 0; i < 4; i++) {
		if (c.inventory[i])
			this->inventory[i] = c.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

Character &Character::operator=(const Character &c) {
	if (this == &c)
		return *this;
	this->name = c.name;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		if (c.inventory[i])
			this->inventory[i] = c.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return *this;
}

void Character::equip(AMateria *m) {
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL && m->getStatusEquip() == UNEQUIP) {
			m->setStatusEquip(EQUIP);
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx] != NULL) {
		this->inventory[idx]->setStatusEquip(UNEQUIP);
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}

AMateria *Character::getMateriaByIdx(int idx) {
	if (idx < 0 || idx > 3)
		return NULL;
	return inventory[idx];
}

std::string const &Character::getName() const {
	return this->name;
}
