#include "Cure.hpp"

Cure::Cure() : AMateria("Cure"){
}

Cure::Cure( const Cure &src ) : AMateria("Cure") {
	*this = src;
}

Cure&	Cure::operator=( Cure const &src ) {
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use( ICharacter& target ){
	std::cout << "Heal " << target.getName() << "'s health point" << std::endl;
}
