#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "destructor called" << std::endl;
}

void	Harl::info()
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put\
 enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::debug()
{
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese\
 triplepicklespecialketchup burger. I really do !" << std::endl;
}

void	Harl::warning()
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming\
 for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "ERROR : This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::unknown()
{
	std::cout << "RANDOM COMPLAIN" << std::endl;
}

void	Harl::complain(const std::string& lvl)
{
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4 && lvl != lvls[i])
		i++;
	switch (i)
	{
		case 0:
			Harl::debug();
			break;
		case 1:
			Harl::debug();
			Harl::info();
			break;
		case 2:
			Harl::debug();
			Harl::info();
			Harl::warning();
			break;
		case 3:
			Harl::debug();
			Harl::info();
			Harl::warning();
			Harl::error();
			break;
		default:
			std::cout << "porbably complaining about random things" << std::endl;
	}
}
