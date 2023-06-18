#include "Zombie.hpp"

int main() {
	Zombie *nick = newZombie("Nick");
	nick->announce();

	randomChump("Bob");
	delete nick;
}