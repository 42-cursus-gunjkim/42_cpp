#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat &wc);
		~WrongCat();
		WrongCat &operator=(const WrongCat &wc);

		void makeSound() const;
		std::string getType() const;
};

#endif