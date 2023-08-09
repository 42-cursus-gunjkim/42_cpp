#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wa);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &wa);

		void makeSound() const;
		const std::string &getType() const;
};

#endif