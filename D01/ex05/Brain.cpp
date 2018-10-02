#include "Brain.hpp"
#include <sstream>

Brain::Brain(void) {
	this->setAddress();
}

Brain::~Brain(void) {}

void		Brain::setAddress(void) {
	std::stringstream ss;

	ss << (this);
	this->_address = ss.str();
}

std::string 	Brain::identify(void) {
	return this->_address;
}