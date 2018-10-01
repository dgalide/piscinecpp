#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main(void) {
	ZombieEvent ze = ZombieEvent();
	ze.setZombieType("FuckType");
	Zombie 		*z = ze.randomChump();

	z->announce();
	delete z;
	return 0;
}