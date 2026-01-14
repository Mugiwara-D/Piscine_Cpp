#include "Zombie.hpp"

Zombie::Zombie( void )
{
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->_name << " has been terminated." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << " : BraiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}
