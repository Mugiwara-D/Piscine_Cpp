
#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " has been terminated." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": Braiiiiiiinnnnzzzz..." << std::endl;
}

