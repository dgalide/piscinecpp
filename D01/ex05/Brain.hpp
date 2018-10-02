#ifndef BRAIN_HPP
 #define BRAIN_HPP

#include <iostream>

class Brain {

public:

	Brain(void);
	~Brain(void);

	void		setAddress(void);
	std::string identify(void);

private:
	std::string _address;
};

#endif