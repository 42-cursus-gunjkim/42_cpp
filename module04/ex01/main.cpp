#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// #include <cstdlib>

// void checkLeak()
// {
// 	system("leaks ex01");
// }

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
	Cat cat;
	Cat another_cat;

	dog.setIdea(0, "Idea 1");
	dog.setIdea(1, "Idea 2");
	cat.setIdea(0, "Cat Idea");
	cat.setIdea(1, "Cat Idea 2");

	for (int i = 0; i < 3; i++) {
		std::cout << "dog's ideas[" << i << "] : "  << dog.getIdea(i) << std::endl;
		std::cout << "another's ideas[" << i << "] : "  << another.getIdea(i) << std::endl;
		std::cout << "cat's ideas[" << i << "] : "  << cat.getIdea(i) << std::endl;
		std::cout << "another_cat's ideas[" << i << "] : "  << another_cat.getIdea(i) << std::endl;
	}

	another = dog;
	another_cat = cat;

	for (int i = 0; i < 3; i++) {
		std::cout << "dog's ideas[" << i << "] : "  << dog.getIdea(i) << std::endl;
		std::cout << "another's ideas[" << i << "] : "  << another.getIdea(i) << std::endl;
		std::cout << "cat's ideas[" << i << "] : "  << cat.getIdea(i) << std::endl;
		std::cout << "another_cat's ideas[" << i << "] : "  << another_cat.getIdea(i) << std::endl;
	}

	Dog other(another);
	Cat other_cat(another_cat);

	for (int i = 0; i < 3; i++) {
		std::cout << "other's ideas[" << i << "] : "  << dog.getIdea(i) << std::endl;
		std::cout << "other_cat's ideas[" << i << "] : "  << other_cat.getIdea(i) << std::endl;
	}

	//atexit(checkLeak);
	return 0;
};