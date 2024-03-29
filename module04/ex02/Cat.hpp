#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &c);
		virtual ~Cat();
		Cat &operator=(const Cat &c);

		virtual void makeSound() const;
		void setIdea(int idx, const std::string &idea);
		const std::string &getIdea(int idx) const;
};

#endif