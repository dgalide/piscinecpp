#ifndef HUMANA_HPP
 #define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	setType(std::string weaponType);
	void	attack(void);

	std::string _name;
	Weapon 		*_weapon;

};

#endif