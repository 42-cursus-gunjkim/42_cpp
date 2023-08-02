#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice &i);
		virtual ~Ice();

		Ice &operator=(const Ice &i);

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif