#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat bureaucrat("bob", 1);
	Form form("Auth", 10, 5);
	std::cout << form << std::endl;
	try {
		bureaucrat.signForm(form);
	} catch (std::exception &expt){
		std::cout << expt.what() << std::endl;
	} 
	return (0);
}
