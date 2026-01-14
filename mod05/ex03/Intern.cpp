#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern& src) {
//    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& src) {
	(void) src;
	return *this;
}

Intern::~Intern() {
}

static AForm*	newShrubbery( const std::string target ) {
	return new ShrubberyCreationForm(target);
}

static AForm*	newRobotomy( const std::string target ) {
	return new RobotomyRequestForm(target);
}

static AForm*	newPresidentialPardon( const std::string target ) {
	return new PresidentialPardonForm(target);
}

typedef	AForm* (*constructorPtr) ( const std::string );

AForm*	Intern::makeForm( std::string name, std::string target ) {
	AForm*	formPtr	= NULL;

	std::string formName[3] = {
		"robotomy", "presidential", "shrubbery"
	};
	constructorPtr	constructor[3] = {&newShrubbery, &newRobotomy, &newPresidentialPardon};

	for (int i = 0; i < 3; i++) {
		if (name == formName[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			formPtr = constructor[i](target);
			break;
		}
	}
	if (formPtr == NULL)
		std::cerr << "Intern couldn't create " << name << std::endl;
	return formPtr;
}
