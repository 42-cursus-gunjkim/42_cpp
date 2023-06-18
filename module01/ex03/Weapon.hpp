#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {

private:
	std::string type;

public:
	Weapon(const std::string &type);
	Weapon(const Weapon &w);
	~Weapon();

	Weapon &operator=(Weapon &w);

	void setType(const std::string &type);
	const std::string &getType() const;
};

#endif