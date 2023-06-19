#include "Zombie.hpp"

int main() {
	Zombie *nick = newZombie("Nick");
	nick->announce();

	Zombie another_nick = *nick;
	another_nick.announce();
	another_nick.setName("another nick");

	randomChump("Bob");
	delete nick;
}