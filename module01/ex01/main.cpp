#include "Zombie.hpp"

int main() {
	Zombie *zombie_horde = zombieHorde(15, "Nick");
	for (int i = 0; i < 15; i++) {
		zombie_horde[i].announce();
	}

	delete[] zombie_horde;
}