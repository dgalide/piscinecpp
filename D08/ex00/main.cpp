#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
	std::list<int>	lst;

	lst.push_back(1);
	lst.push_back(10);

	try {
		std::cout << easyfind(lst, 10) << std::endl;
	}
	catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << easyfind(lst, 18) << std::endl;
	}
	catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}


	std::vector<int>	v;

	v.push_back(5);
	v.push_back(6);

	try {
		std::cout << easyfind(v, 0) << std::endl;
	}
	catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << easyfind(v, 5) << std::endl;
	}
	catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}