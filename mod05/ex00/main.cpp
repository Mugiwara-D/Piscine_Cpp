#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat bureaucrat("bob", 1);
	std::cout << bureaucrat << std::endl;
	try {
		bureaucrat.incrGrade();
	} catch (Bureaucrat::highException &expt){
		std::cout << expt.what() << std::endl;
	}
	try {
		bureaucrat.decrGrade();
	} catch (Bureaucrat::lowException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;
	return (0);
}
