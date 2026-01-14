#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat bureaucrat("bob", 1);
	ShrubberyCreationForm form("chen");
	RobotomyRequestForm form1("Robot");
	PresidentialPardonForm form2("peasent");

	bureaucrat.executeForm(form);
	bureaucrat.executeForm(form1);
	bureaucrat.executeForm(form2);
	return (0);
}
