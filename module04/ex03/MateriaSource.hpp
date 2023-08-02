#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *memory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &ms);
		virtual ~MateriaSource();
		MateriaSource &operator=(const MateriaSource &ms);
		virtual void learnMateria(AMateria *m);
		virtual AMateria *createMateria(std::string const &type);
};

#endif