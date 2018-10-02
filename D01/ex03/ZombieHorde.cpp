#include "ZombieHorde.hpp"
#include "Zombie.hpp"
	
ZombieHorde::ZombieHorde(int n) {

	listZombie = new std::vector<Zombie*>();

	srand(time(0));
	std::string names[] = {"Dallas", "Ikagaru", "Fistolla", "Zlarto", "Yoplait", "GloriousBastard", "GloriousFucker", "GoodBoy", "GloriousCaunt"};
	std::string type = "noType";
	nbZombie = n;

	for (int i = 0; i < n; i++) {
		listZombie->push_back (new Zombie(type, names[(rand() % 9)]));
	}
}

ZombieHorde::~ZombieHorde(void) {
	delete listZombie;
}

void ZombieHorde::announce(void) {

	for (int i = 0; i < nbZombie; i++) {
		Zombie *z = listZombie->at(i);
		z->announce();
	}
} 