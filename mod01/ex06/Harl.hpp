#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private :
		void	info();
		void	debug();
		void	warning();
		void	error();
		void	unknown();

	public:
		Harl();
		~Harl();
		void	complain(const std::string& lvl);
};
#endif
