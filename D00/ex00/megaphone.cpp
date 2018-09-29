#include <iostream>

int main(int ac, char **argv)
{
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < ac;i++) {
			for (int j = 0; argv[i][j]; j++) {
				if ((argv[i][j] >= 'a' && argv[i][j] <= 'z')) {
					argv[i][j] = toupper(argv[i][j]);
				}
			}
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return 0;
}