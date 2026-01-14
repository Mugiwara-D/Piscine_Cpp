#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
void	easyfind( T& array, int target )
{
	if ( std::find(array.begin(), array.end(), target) != array.end())
		std::cout << target << " Found." << std::endl;
	else
		std::cout << target << " Not Found." << std::endl;
}

#endif // EASYFIND_HPP
