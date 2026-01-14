#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("wrongAnimal"){
    std::cout << this->_type << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type) {
    std::cout << "wrong " << this->_type << "Parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Wrong Animal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Wrong Animal sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->_type;
}
