#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	plusOne( T &n ) {
	n += 1;
}

template <typename T>
void	ft_print( T &e ) {
	std::cout << e << std::endl;
}

template <typename A, typename F>
void	iter( A* array, size_t len, F fuc ) {
	for (size_t i = 0; i < len; i++)
		fuc(array[i]);
}

#endif // ITER_HPP
