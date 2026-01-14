#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	std::cout << "default constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	std::cout << "initialisation constructor called" << std::endl;
}

Point::Point( const Point &src ) : _x(src._x), _y(src._y)
{
	std::cout << "copy constructor called" << std::endl;
}

Point::~Point( void )
{
	std::cout << "point destructor called" << std::endl;
}

Point&	Point::operator =( const Point &src )
{
	if (this != &src) {
		(Fixed) this->_x = src.getX();
		(Fixed) this->_y = src.getY();
	}

	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}
