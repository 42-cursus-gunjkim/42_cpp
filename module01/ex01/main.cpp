#include "Zombie.hpp"

int main() {
	Zombie *zombie_horde = zombieHorde(15, "Nick");
	for (int i = 0; i < 15; i++) {
		zombie_horde[i].announce();
		if (i % 2 == 0)
			zombie_horde[i].setName("even Nick");
		else
			zombie_horde[i].setName("odd Nick");
	}

	delete[] zombie_horde;
}