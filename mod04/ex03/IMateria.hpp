#ifndef IMATERIA_HPP
#define IMATERIA_HPP

#include "AMateria.hpp"

class IMateria
{
	public:
		IMateria();
		virtual ~IMateria();

		virtual void	learnMateria( AMateria* ) = 0;
		virtual AMateria*	creatMateria( std::string const &type ) = 0;
};

#endif // IMATERIA_HPP
