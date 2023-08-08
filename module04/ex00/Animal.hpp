#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &a);
		virtual ~Animal();
		Animal &operator=(const Animal &a);

		virtual void makeSound() const;
		virtual std::string getType() const; 
};

#endif