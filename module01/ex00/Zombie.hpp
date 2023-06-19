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
	Zombie(const Zombie &z);
	Zombie &operator=(const Zombie &z);

	void announce();
	void setName(const std::string &name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif