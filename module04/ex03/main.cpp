
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "World.hpp"
#include <iostream>

//#include <cstdlib>

//void checkLeak()
//{
//	system("leaks ex03");
//}

void equipAndValidate(int idx, World &world, ICharacter *me) {
	me->equip(world.getMateria(idx));
	world.validateMateria(idx);
}

void unequipAndSet(int idx, World &world, ICharacter *me) {
	AMateria *tmp = me->getMateriaByIdx(idx);
	me->unequip(idx);
	world.setMateria(tmp);
}

void initWorldSystem(World &world, IMateriaSource *src) {
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	for (int i = 0; i < 22; i++) {
		if (i % 2 == 0)
			world.setMateria(src->createMateria("ice"));
		else
			world.setMateria(src->createMateria("cure"));
	} 
}

void equipOver4Times(World &world, ICharacter *me, ICharacter *bob) {
	equipAndValidate(0, world, me);
	equipAndValidate(1, world, me);
	equipAndValidate(2, world, me);
	equipAndValidate(3, world, me);
	equipAndValidate(4, world, me);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(5, *bob); //cannot attack because 5 is out of range
}

void equipAndUnequip(World &world, ICharacter *me, ICharacter *bob) {
	equipAndValidate(0, world, me);
	equipAndValidate(1, world, me);
	equipAndValidate(2, world, me);
	equipAndValidate(3, world, me);
	unequipAndSet(0, world, me);
	unequipAndSet(1, world, me);
	unequipAndSet(2, world, me);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
}

void doubleEquip(World &world, ICharacter *me, ICharacter *bob) {
	equipAndValidate(0, world, bob);
	equipAndValidate(0, world, me);
	me->use(0, *bob);
	bob->use(0, *me);
}

void commonTest(World &world, ICharacter *me, ICharacter *bob) {
	equipAndValidate(13, world, me);
	equipAndValidate(13, world, bob);
	me->use(0, *bob);
	bob->use(0, *me); //13 alreay equipped

	unequipAndSet(3, world, me); //3 is empty
	unequipAndSet(0, world, bob); //0 is empty

	me->use(0, *bob); //attack to bob
	bob->use(0, *me); //cannot attack

	World another = world;
	Character me2("me2");
	Character me3("me3");
	equipAndValidate(15, world, &me2);
	equipAndValidate(16, world, &me3);
	me2.use(0, *bob);
	me3.use(0, *bob);
	me2 = me3;
	me2.use(0, *bob);
	me3.use(0, *bob);
}

void basicTest(ICharacter *me, ICharacter *bob, IMateriaSource *src) {
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
}

int main()
{
	World world;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	initWorldSystem(world, src);
	//equipOver4Times(world, me, bob);
	//equipAndUnequip(world, me, bob);
	//doubleEquip(world, me, bob);

	basicTest(me, bob, src);

	//commonTest(world, me, bob);

	delete bob;
	delete me;
	delete src;
	//atexit(checkLeak);
	return 0;
}