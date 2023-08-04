#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ms) {
	for (int i = 0; i < 4; i++) {
		if (ms.memory[i])
			this->memory[i] = ms.memory[i]->clone();
		else
			this->memory[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->memory[i])
			delete this->memory[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms) {
	if (this == &ms)
		return (*this);
	
	for (int i = 0; i < 4; i++) {
		if (this->memory[i])
			delete this->memory[i];
		if (ms.memory[i])
			this->memory[i] = ms.memory[i]->clone();
		else
			this->memory[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->memory[i] == NULL) {
			this->memory[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->memory[i] && this->memory[i]->getType() == type)
			return (this->memory[i]->clone());
	}
	return (NULL);
}
