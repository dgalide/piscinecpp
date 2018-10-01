#include "Pony.hpp"

int Pony::nbPonies = 0;

Pony::Pony(int size, int weight) {
	_size = size;
	_weight = weight;
	_index = nbPonies;
	nbPonies += 1;
}

Pony::~Pony(void) {
	std::cout << "Destructor Called" << " Index == " << _index << std::endl;
}

void Pony::displaySize(void) {
	std::cout << "Size :: " << _size << std::endl;
}

void Pony::displayWeight(void) {
	std::cout << "Weight :: " << _weight << std::endl;
}