#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) :
	AForm("RobotomyRequestForm", 72, 45, false ), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm(src), _target(src._target){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	( void ) src;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const {
	if ( executor.getGrade() > this->getExecGrade() )
		throw AForm::toLowException();
	else {
		static int i;
		if ( i % 2 == 0 )
			std::cout << "BZZZT " << _target << " has been robotomize!" << std::endl;
		else
			std::cout << "Robotomization failed " << _target << " is dead..." << std::endl;
		i++;
	}
}
