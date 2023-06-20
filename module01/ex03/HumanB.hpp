#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

private:
	std::string name;
	Weapon *weapon;

public:
	HumanB();
	HumanB(const std::string &name);
	~HumanB();
	HumanB(const HumanB &h);
	HumanB& operator=(const HumanB &h);

	void setWeapon(Weapon &weapon);
	void attack();
};

#endif