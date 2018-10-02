#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) {
	type = new std::string(weaponType);
}

Weapon::~Weapon(void) {}

void Weapon::setType(std::string weaponType) {
	this->type = new std::string(weaponType);
}

const std::string	Weapon::getType(void) {
	const std::string output = *(this->type);
	return output;
}