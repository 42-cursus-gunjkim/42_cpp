#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	int numberOfAnimals  = 2;

	Animal **animals = new Animal*[numberOfAnimals];

	for (int i = 0; i < numberOfAnimals; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < numberOfAnimals; i++) {
		delete animals[i];
	}
	delete[] animals;
};