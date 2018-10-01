#include <iostream>

void memoryLeak() {
	std::string*        panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;

	// Comment to see the leaks
	delete panthere;
}

int main(void) {
	memoryLeak();

	// uncomment to see the leaks using leaks command
	// while (true) {}
}