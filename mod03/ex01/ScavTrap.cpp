#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std ::endl;
	_type = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap( const std::string &name )
{
	std::cout << "ScavTrap naming constructor called" << std ::endl;
	_type = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_name = name;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap &src ) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

void	ScavTrap::guardGate( void )
{
	if (_hitPoints > 0)
		std::cout << "ScavTrap " << _name << " is guarding!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is not guarding..." << std::endl;

}
