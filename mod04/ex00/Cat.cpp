#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow meow give me food slave" << std::endl;
}
