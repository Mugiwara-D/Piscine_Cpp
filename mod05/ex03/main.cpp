#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	AForm *a;
	AForm *b;
	AForm *c;

	std::cout << std::endl;

	Intern Arnaldo;

	a = Arnaldo.makeForm("robotomy", "Ebil");
	std::cout << std::endl;
	b = Arnaldo.makeForm("presidential", "Ebil");
	std::cout << std::endl;
	c = Arnaldo.makeForm("shrubbery", "Ebil");
	std::cout << std::endl;

	Arnaldo.makeForm("foo", "Ebil");

	if (a != NULL)
		delete a;
	if (b != NULL)
		delete b;
	if (c != NULL)
		delete c;
	return 0;
}
