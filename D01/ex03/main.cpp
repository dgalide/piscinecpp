#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int main(void) {
	ZombieHorde *zh = new ZombieHorde(10);
	zh->announce();
	return 0;
}