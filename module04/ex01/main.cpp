#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//#include <cstdlib>

//void checkLeak()
//{
//	system("leaks ex01");
//}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n\n" << "------------------array test-------------------" << "\n\n";
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

	std::cout << "\n\n" << "------------------copy test-------------------" << "\n\n";
	Dog dog;
	Dog another;

	dog.setIdea(0, "Idea 1");
	dog.setIdea(1, "Idea 2");

	for (int i = 0; i < 3; i++) {
		std::cout << "dog's ideas[" << i << "] : "  << dog.getIdea(i) << std::endl;
		std::cout << "another's ideas[" << i << "] : "  << another.getIdea(i) << std::endl;
	}

	another = dog;

	for (int i = 0; i < 3; i++) {
		std::cout << "dog's ideas[" << i << "] : "  << dog.getIdea(i) << std::endl;
		std::cout << "another's ideas[" << i << "] : "  << another.getIdea(i) << std::endl;
	}


	//atexit(checkLeak);
	return 0;
};