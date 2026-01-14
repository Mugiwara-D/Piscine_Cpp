#include "AForm.hpp"

AForm::AForm(){
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm( std::string name, int signGrade, int execGrade, bool signe) : _name(name), 
	_signed(signe), _signGrade(signGrade), _execGrade(execGrade) {
		if ( signGrade < 1 || execGrade < 1 )
			throw AForm::toHighException();
		if ( execGrade > 150 || signGrade > 150 )
			throw AForm::toLowException();
}

AForm::AForm(const AForm& src) {
	_name = src._name;
	_signed = src._signed;
	_signGrade = src._signGrade;
	_execGrade = src._execGrade;
}

AForm& AForm::operator=(const AForm& src) {
	if (this != &src)
		_signed = src.getSigned();
	return *this;
}

AForm::~AForm() {
}

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getSigned() const {
	return _signed;
}

int		AForm::getSignGrade() const {
	return _signGrade;
}

int		AForm::getExecGrade() const {
	return _execGrade;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::toHighException();
	else
		_signed = true;
}
std::ostream& operator<<( std::ostream& ost, const AForm& src ) {
	ost << "AForm info:" << std::endl;
	ost << "AForm : " << src.getName() << std::endl
		<< "Grade to sign: " << src.getSignGrade() << std::endl
		<< "Grade to execute: " << src.getExecGrade() << std::endl;
	return ost;
}
