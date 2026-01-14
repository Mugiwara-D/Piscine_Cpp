#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default Constructor Called" << std::endl;
	_nbr = 0;
}

Fixed::Fixed(Fixed &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawbits() member function called" << std::endl;
	return (this->_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nbr = raw;
}

Fixed &Fixed::operator = (Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nbr = src.getRawBits();
	return (*this);
}
