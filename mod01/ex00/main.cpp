#include "Zombie.hpp"

int	main( void )
{
	std::string name;

	std::cout << "Creating zombie on the stack." << std::endl;
	std::cout << "what Zombie name :" << std::flush;
	std::cin >> name;

	Zombie zombie1(name);

	std::cout << "Creating zombie on the heap." << std::endl;
	std::cout << "what Zombie name :" << std::flush;
	std::cin >> name;

	Zombie *zombie2 = newZombie(name);
	zombie2->announce();
	delete zombie2;

	std::cout << "randomChump call" << std::endl;
	randomChump("randy");
	
	return 0;
}
