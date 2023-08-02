#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &d);
		virtual ~Dog();
		Dog &operator=(const Dog &d);

		virtual void makeSound() const;
		virtual std::string getType() const;
};

#endif