#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	HumanA(const HumanA &h);
	HumanA& operator=(const HumanA &h);

	void attack();
};

#endif