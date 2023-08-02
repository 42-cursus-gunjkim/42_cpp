#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string type;
		AMateria() {}
	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &a);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &a);

		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif