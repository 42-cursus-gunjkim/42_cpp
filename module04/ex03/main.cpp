
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "World.hpp"
#include <cstdlib>
#include <iostream>

void checkLeak()
{
	system("leaks ex03");
}

int main()
{
	World world;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	//AMateria* tmp;
	world.setMateria(src->createMateria("ice"));
	me->equip(world.getMateria("ice"));
	world.setMateria(src->createMateria("cure"));
	me->equip(world.getMateria("cure"));
	me->unequip(1);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "1" << std::endl;
	delete bob;
	std::cout << "2" << std::endl;
	delete me;
	std::cout << "3" << std::endl;
	delete src;
	std::cout << "4" << std::endl;
	atexit(checkLeak);
	return 0;
}