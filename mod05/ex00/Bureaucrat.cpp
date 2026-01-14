#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
    std::cout << "Parameterize constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::highException();
	if (grade > 150)
		throw Bureaucrat::lowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src)
		_grade = src.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrGrade(){
	if (_grade - 1 < 1)
		throw Bureaucrat::highException();
	_grade--;
}

void	Bureaucrat::decrGrade(){
	if (_grade + 1 > 150)
		throw Bureaucrat::lowException();
	_grade++;
}

std::ostream& operator<<( std::ostream& ost, const Bureaucrat& src ){
	ost << src.getName() << ", Bureaucratique grade : " << src.getGrade();
	return ost;
}
