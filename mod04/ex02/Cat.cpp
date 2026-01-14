#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain;
}

Cat::Cat( const Cat &src ) : Animal()
{
	_brain = NULL;
	*this = src;
	std::cout << "Cat copy constructir called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "meow meow give me food slave" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (_brain);
}

Cat	&Cat::operator =( const Cat &src )
{
	std::cout << "Cat = operator called" << std::endl;
	if (_brain)
		delete _brain;
	_brain = new Brain(*src._brain);
	_type = src._type;
	return (*this);
}
