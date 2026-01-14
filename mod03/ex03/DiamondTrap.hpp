#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap( DiamondTrap &src );
		DiamondTrap( std::string name );
		DiamondTrap& operator =( DiamondTrap& src );

        std::string     getName() const;
		void            WhoAmi();
};

#endif
