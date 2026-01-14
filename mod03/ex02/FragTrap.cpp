#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_type = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

FragTrap::FragTrap( const std::string name )
{
	std::cout << "FragTrap naming constructor called" << std::endl;
	_type = "FragTrap";
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

FragTrap::FragTrap( FragTrap &src ): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFiveGuys( void )
{
	std::string	rep;

	if (_hitPoints > 0)
	{
		std::cout << "FragTrap " << _name << " ask for a highfive." << std::endl;
		while (rep != "y" && rep != "n")
		{
			std::cout << "Highfive ?(y/n)" << std::endl;
			if (!std::getline(std::cin, rep))
				break ;
		}
		if (rep == "y")
			std::cout << "FragTrap " << _name << ": \"nice bro!\"" << std::endl;
		else if (rep == "n")
			std::cout << "FragTrap " << _name << ": \"not nice bro!\"" << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " his dead and his unable to Highfive." << std::endl;
}
