#include "easyfind.hpp"

int	main( int ac, char **av )
{
	if ( ac != 2 )
		return 1;

	int	a[] = {0,1,2,3,4,5,6,7,8,9};

	std::vector<int>	v(a, a + sizeof(a) / sizeof(int));
	std::list<int>		l(a, a + sizeof(a) / sizeof(int));

	easyfind( v, std::atoi(av[1]) );
	easyfind( l, std::atoi(av[1]) );
	return 0;
}
