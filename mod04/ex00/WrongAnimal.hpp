#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal( std::string type );
		WrongAnimal( const WrongAnimal& src );
		WrongAnimal& operator=( const WrongAnimal& src );
		~WrongAnimal();

		std::string		getType() const;
		void	makeSound() const;
};

#endif // WRONGANIMAL_HPP
