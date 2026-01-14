#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain;
}

Dog::Dog( const Dog &src ) : Animal()
{
	_brain = NULL;
	*this = src;
	std::cout << "Dog copy constructir called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (_brain);
}

Dog	&Dog::operator =( const Dog &src )
{
	std::cout << "Dog = operator called" << std::endl;
	if (_brain)
		delete _brain;
	_brain = new Brain(*src._brain);
	_type = src._type;
	return (*this);
}
