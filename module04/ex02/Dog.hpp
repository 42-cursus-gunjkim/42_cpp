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
		void setIdea(int idx, const std::string &idea);
		const std::string &getIdea(int idx) const;
};

#endif