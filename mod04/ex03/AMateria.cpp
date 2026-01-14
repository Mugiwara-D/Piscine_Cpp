#include "AMateria.hpp"

AMateria::AMateria() : _type("rando") {
}

AMateria::AMateria( std::string const &type ) : _type(type) {
	std::cout << "AMateria " << this->_type << " created" << std::endl;
}

AMateria::~AMateria(){
}

AMateria::AMateria(const AMateria& src) {
	*this = src;
}

AMateria& AMateria::operator=(const AMateria& src) {
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string const	&AMateria::getType() const{
	return (this->_type);
}

AMateria*	AMateria::clone() const {
	return (AMateria*) this;
}

void	AMateria::use( ICharacter& target ) {
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
