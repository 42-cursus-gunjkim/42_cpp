#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
		Character() {}
	public:
		Character(std::string const &name);
		Character(const Character &c);
		virtual ~Character();
		Character &operator=(const Character &c);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		virtual AMateria *getMateriaIdx(int idx);
};

#endif