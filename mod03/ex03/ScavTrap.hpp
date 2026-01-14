#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap( const std::string &name );
		ScavTrap( ScavTrap &src );
		~ScavTrap();

		void	guardGate( void ); 
};
#endif
