#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( const char* str );
		Intern( const Intern& src );
		Intern& operator=( const Intern& src );
		~Intern();

		AForm*	makeForm( std::string name, std::string target );
};

#endif // INTERN_HPP
