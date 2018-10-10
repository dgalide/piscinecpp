#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>

template <typename T>
int		easyfind( T & a, int b)
{
	typename T::iterator	it = std::find(a.begin(), a.end(), b);
    
	if (it != a.end())
			return *it;
	throw std::logic_error("Not Found");
}

#endif