#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
	_type = "Animal";
}

Animal::Animal( Animal &src )
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal &Animal::operator =( const Animal &src )
{
	std::cout << "Overload operator = used on " << this << " from " << &src << std::endl;
	if (this != &src)
		_type = src.getType();
	return *this;
}

std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::setType( const std::string &newType )
{
	_type = newType;
}

void	Animal::makeSound() const
{
	std::cout << "Random Animal sound" << std::endl;
}
