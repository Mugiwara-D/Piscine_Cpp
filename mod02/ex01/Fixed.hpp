#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int	_nbr;
		static const int _bits;
	public:
		Fixed();
		Fixed( const Fixed &src );
		Fixed( const int &i_param );
		Fixed( const float &f_param );
		~Fixed();
		Fixed &operator = ( const Fixed &src );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator << (std::ostream &o, Fixed const &src);

#endif
