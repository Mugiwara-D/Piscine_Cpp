#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat( const Cat &src );
		Cat	&operator =( const Cat &src );
		virtual void makeSound() const;
		Brain	*getBrain() const;
	private:
		Brain	*_brain;
};

#endif
