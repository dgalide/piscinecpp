#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(void): type("noTypeYet") {}

ZombieEvent::~ZombieEvent(void) {}

void 	ZombieEvent::setZombieType(std::string type) {
	this->type = type;
}

Zombie 	*ZombieEvent::newZombie(std::string name) {
	return (new Zombie(this->type, name));
}

Zombie 	*ZombieEvent::randomChump(void) {

	std::string names[] = {"Dallas", "Ikagaru", "Fistolla", "Zlarto", "Yoplait", "GloriousBastard", "GloriousFucker", "GoodBoy", "GloriousCaunt"};

	srand(time(0));
    int index = rand() % 9;
    Zombie *z = this->newZombie(names[index]);
    return (z);
}