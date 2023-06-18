#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {

private:
	std::string name;

public:
	Zombie();
	~Zombie();
	Zombie(Zombie &z);
	Zombie &operator=(Zombie &z);

	void announce();
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name);

#endif