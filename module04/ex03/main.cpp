
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "World.hpp"
#include <cstdlib>

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
	world.setMateria(me->getMateriaIdx(0));
	me->unequip(0);
	world.setMateria(me->getMateriaIdx(1));
	me->unequip(1);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	atexit(checkLeak);
	return 0;
}