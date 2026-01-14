#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof nice food master" << std::endl;
}
