#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int	_nbr;
		static const int _bits;
	public:
		Fixed();
		Fixed( Fixed &src );
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed &operator = (Fixed &src);
};



#endif
