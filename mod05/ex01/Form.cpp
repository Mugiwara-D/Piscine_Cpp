#include "Form.hpp"

Form::Form() : _name("rando"), _signed(false), _signGrade(0), _execGrade(0){
    std::cout << "Default constructor called" << std::endl;
}

Form::Form( std::string name, int signGrade, int execGrade ) : _name(name), 
	_signGrade(signGrade), _execGrade(execGrade)  {
		if ( signGrade < 1 || execGrade < 1 )
			throw Form::toHighException();
		if ( execGrade > 150 || signGrade > 150 )
			throw Form::toLowException();
}

Form::Form(const Form& src) : _name(src.getName()), _signed(src.getSigned()), 
	_signGrade(src.getSigned()), _execGrade(src.getExecGrade()){
}

Form& Form::operator=(const Form& src) {
	if (this != &src)
		_signed = src.getSigned();
	return *this;
}

Form::~Form() {
}

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSigned() const {
	return _signed;
}

int		Form::getSignGrade() const {
	return _signGrade;
}

int		Form::getExecGrade() const {
	return _execGrade;
}

void	Form::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::toHighException();
	else
		_signed = true;
}
std::ostream& operator<<( std::ostream& ost, const Form& src ) {
	ost << "Form info:" << std::endl;
	ost << "Form : " << src.getName() << std::endl
		<< "Grade to sign: " << src.getSignGrade() << std::endl
		<< "Grade to execute: " << src.getExecGrade() << std::endl;
	return ost;
}
