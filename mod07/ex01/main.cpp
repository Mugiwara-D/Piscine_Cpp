#include "iter.hpp"

int	main( void )
{
	int aray[] = {0,0,0};
	char str[] = "hello world";

	std::cout << str << std::endl;
	::iter(str, 11, ::plusOne<char>);
	std::cout << str << std::endl;

	::iter(aray, 3, ::ft_print<int>);
	::iter(aray, 3, ::plusOne<int>);
	::iter(aray, 3, ::plusOne<int>);
	::iter(aray, 3, ::ft_print<int>);


	return 0;
}
