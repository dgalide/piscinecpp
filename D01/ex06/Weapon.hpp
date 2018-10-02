#ifndef WEAPON_HPP
 #define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(std::string weaponType);
	~Weapon(void);

	void				setType(std::string weaponType);
	const std::string	getType(void);

	std::string 		*type;
};

#endif