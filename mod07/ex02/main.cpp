#include "Array.hpp"

int	main( void )
{
	Array<int> A(9);
	Array<int> b;

	A[4] = 42;

	std::cout << A[4] << std::endl;
	std::cout << A.size() << std::endl;
	std::cout << b.size() << std::endl;

	return 0;
}