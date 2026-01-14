#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_bag[4];

	public:
		Character( const std::string& name );
		Character( const Character& src );
		Character& operator=( const Character& src );
		~Character();

		const std::string	&getName() const;
		void				equip( AMateria* m );
		void				unEquip( int idx );
		void				use( int idx, ICharacter& target );
		void				showStats();
};

#endif // CHARACTER_HPP
