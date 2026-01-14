#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "void";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( Brain &src )
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

std::string*	Brain::getIdea()
{
	return (_ideas);
}

Brain	&Brain::operator =( const Brain &src )
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	std::cout << "Brain = operator called" << std::endl;
	return (*this);
}

void	Brain::showIdea()
{
	for (int i = 0; i < 100; i++)
		std::cout << _ideas[i] << std::endl;
}

void	Brain::setIdea( std::string idea )
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}
