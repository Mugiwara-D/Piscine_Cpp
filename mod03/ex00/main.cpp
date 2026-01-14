#include "ClapTrap.hpp"

int	main()
{
	std::string str("lol2");
	ClapTrap a("lol1");
	ClapTrap b(str);

	int i(0);
	a.displayStats();
	b.displayStats();
	while (i < 10)
	{
		a.attack("herl");
		b.takeDamage(a.getAd());
		b.beRepaired(10);
		a.displayStats();
		b.displayStats();
		i++;
	}
	return (0);
}
