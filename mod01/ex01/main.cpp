#include "Zombie.hpp"

#define n 4

int main( void )
{
	Zombie *zombies = zombieHorde(n, "zombie");

	for (int i = 0; i < n; i++){
		zombies[i].announce();
	}

	delete [] zombies;
	return 0;
}
