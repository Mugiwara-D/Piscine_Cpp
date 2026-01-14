#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	public :
		Brain();
		Brain( Brain &src );
		~Brain();
		Brain &operator =( const Brain &src );
		std::string *getIdea();
		void	showIdea();
		void	setIdea( std::string idea );
	private :
		std::string	_ideas[100];
};

#endif
