#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
 
	std::cout << std::endl;
	std::cout << "meta->getType(): " << meta->getType() << std::endl;
	std::cout << "j->getType(): " << j->getType() << std::endl;
	std::cout << "i->getType(): " << i->getType() << std::endl;

	std::cout << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	std::cout << std::endl;

	std::cout << "----------- Wrong Version ------------" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongJ = new WrongCat();

	std::cout << std::endl;
	std::cout << "wrongMeta->getType(): " << wrongMeta->getType() << std::endl;
	std::cout << "wrongJ->getType(): " << wrongJ->getType() << std::endl;

	std::cout << std::endl;
	wrongMeta->makeSound();
	wrongJ->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongJ;
	return 0;
}