#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materias[4];

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& src );
		MateriaSource& operator=( const MateriaSource& src );
		~MateriaSource();

		AMateria*	getMateria( const std::string &type );
		AMateria*	creatMateria( const std::string &type );
		void		learnMateria( AMateria* );
};

#endif // MATERIASOURCE_HPP
