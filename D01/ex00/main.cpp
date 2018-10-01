#include "Pony.hpp"

void ponyOnTheHeap(bool deleteBool) {
	Pony *p1 = new Pony(1, 1);

	if (deleteBool) {
		delete p1;
	}
}

void ponyOnTheStack(void) {
	Pony p2 = Pony(2, 2);
}

int main(int ac, char **av) {

	std::cout << "ponyOnTheHeap()" << std::endl;
	if (ac == 2 && !(strcmp(av[1], "delete"))) {
		ponyOnTheHeap(true);
	} else {
		ponyOnTheHeap(false);
	}
	std::cout << "exited ponyOnTheHeap()" << std::endl;
	std::cout << "ponyOnTheStack()" << std::endl;
	ponyOnTheStack();
	std::cout << "exited ponyOnTheStack()" << std::endl;

	return 0;
}