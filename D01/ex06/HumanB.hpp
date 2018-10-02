#ifndef HUMANB_HPP
 #define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {

public:

	HumanB(std::string name);
	~HumanB(void);

	void	setWeapon(Weapon &weapon);
	void	attack(void);

	Weapon 			*_weapon;
	std::string		_name;

};

#endif