#include "Ice.hpp"

Ice::Ice() : AMateria("Ice"){
}

Ice::Ice(const Ice& src) : AMateria("Ice"){
	*this = src;
}

Ice& Ice::operator=(const Ice& src) {
	if (this != &src)
		this->_type =src._type;
	return *this;
}

Ice::~Ice() {
}

AMateria*	Ice::clone() const{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target){
	std::cout << "Shoot a ice bolt at " << target.getName() << std::endl;
}
