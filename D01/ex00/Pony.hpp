#ifndef PONY_HPP
 #define PONY_HPP

 #include <iostream>

class Pony {

public:
	int _size;
	int _weight;
	int _index;

	static int nbPonies;


	Pony(int size, int weight);
	~Pony(void);

	void	displaySize(void);
	void	displayWeight(void);
};

#endif