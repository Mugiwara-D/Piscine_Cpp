#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	public:
		Animal();
		Animal( Animal &src );
		virtual ~Animal();
		Animal &operator =(const Animal &src);
		std::string getType() const;
		void	setType( const std::string &newType );
		virtual	void	makeSound() const;

	protected:
		std::string	_type;
};
#endif
