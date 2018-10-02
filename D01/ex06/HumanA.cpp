#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(&weapon), _name(name) {}

HumanA::~HumanA(void) {}

void		HumanA::setType(std::string weaponType) {
	this->_weapon->setType(weaponType);
}

void		HumanA::attack(void) {
	std::cout << _name << " attacks with his " << this->_weapon->getType() << std::endl;
}