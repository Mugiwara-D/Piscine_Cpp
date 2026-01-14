#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : 
	AForm("PresidentialPardonForm", 25, 5, false), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : 
	AForm(src), _target(src._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src ) {
	(void) src;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::toLowException();
	else
		std::cout << _target << " has been granted the pardon of Zaphob Beeblerox !"
			<< std::endl;
}
