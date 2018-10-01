#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name) {
	this->name = name;
	this->type = type;
}

Zombie::~Zombie(void) {}

void Zombie::announce(void) {
	std::cout << '<' << this->name << " (" << this->type << ")> " << "Braiiiiiiinnnssss..." <<std::endl;
}