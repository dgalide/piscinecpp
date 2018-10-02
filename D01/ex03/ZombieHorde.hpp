#ifndef ZOMBIEHORDE_HPP
 #define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <vector>

class ZombieHorde {

public:

	ZombieHorde(int n);
	~ZombieHorde(void);

	std::vector<Zombie*> 		*listZombie;
	int					nbZombie;

	void announce(void);
};

#endif