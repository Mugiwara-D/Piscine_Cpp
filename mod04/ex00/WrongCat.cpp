#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << this->_type << "constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Wrong Cat desctructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "cui cui" << std::endl;
}
