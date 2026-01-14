#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		void	announce( void );
		Zombie	*newZombie( std::string name );
		void	setName( std::string name );
};

Zombie	*zombieHorde( int n, std::string name );

#endif
