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
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		Fixed &operator =( const Fixed &src );
		bool	operator >( const Fixed &src );
		bool	operator <( const Fixed &src );
		bool	operator >=( const Fixed &src );
		bool	operator <=( const Fixed &src );
		bool	operator ==( const Fixed &src );
		bool	operator !=( const Fixed &src );
		Fixed	operator +( const Fixed &src );
		Fixed	operator -( const Fixed &src );
		Fixed	operator *( const Fixed &src );
		Fixed	operator /( const Fixed &src );
		Fixed	operator ++( int );
		Fixed&	operator ++( void );
		Fixed	operator --( int );
		Fixed&	operator --( void );
		static	Fixed&	min(Fixed &src1, Fixed &src2);
		static	Fixed&	max(Fixed &src1, Fixed &src2);
		static	Fixed	max(const Fixed &src1, const Fixed &src2);
		static	Fixed	min(const Fixed &src1, const Fixed &src2);
};

std::ostream &operator << (std::ostream &o, Fixed const &src);

#endif
