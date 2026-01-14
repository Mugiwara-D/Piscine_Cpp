#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default Constructor Called" << std::endl;
	_nbr = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int &i_param)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i_param << _bits);
}

Fixed::Fixed(const float &f_param)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f_param * (1 << _bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "setRawbits() called" << std::endl;
	return (this->_nbr);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_nbr / (1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (_nbr >> _bits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nbr = raw;
}

Fixed &Fixed::operator = (const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nbr = src.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &src)
{
	o << src.toFloat();
	return o;
}
