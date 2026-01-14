#include "Base.hpp"
#include <cstdlib>

Base*	generate( void ) {
	if (std::rand() % 3 == 0)
		return ( new A );
	else if (std::rand() % 3 == 1)
		return ( new B );
	else
		return ( new C );
}

void	identify( Base* ptr ) {
	if (ptr == NULL)
		std::cout << "Null pointer" << std::endl;
	else if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown Class" << std::endl;
}

void	identify( Base& ptr ) {
	try {
		A& a = dynamic_cast<A&>(ptr);
		std::cout << "A" << std::endl;
		(void) a;
	} catch(const std::exception& e) {}
	try {
		B& b = dynamic_cast<B&>(ptr);
		std::cout << "B" << std::endl;
		(void) b;
	} catch(const std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(ptr);
		std::cout << "C" << std::endl;
		(void) c;
	} catch(const std::exception& e) {}
}

int	main(void)
{
	Base*	a = generate();
	Base*	b = generate();
	Base*	c = generate();
	Base*	d = generate();

	std::cout << "a* = "; identify(a);
	std::cout << "a& = "; identify(*a); std::cout << std::endl;

	std::cout << "b* = "; identify(b);
	std::cout << "b& = "; identify(*b); std::cout << std::endl;

	std::cout << "c* = "; identify(c);
	std::cout << "c& = "; identify(*c); std::cout << std::endl;

	std::cout << "d* = "; identify(d);
	std::cout << "d& = "; identify(*d); std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	delete d;
	return 0;
}
