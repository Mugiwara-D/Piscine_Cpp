#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <stdint.h>

class Span
{
	private:
		std::vector< int >	_data_vect;
		uint32_t			_n;

	public:
		Span( void );
		Span( uint32_t n );
		Span( const Span& src );
		Span& operator=( const Span& src );
		~Span();

		void	addNumber( int num );

		uint32_t	longestSpan( void ) const;
		uint32_t	shortestSpan( void ) const;

		const std::vector<int>*	getData( void ) const;
};

std::ostream&   operator<<( std::ostream& o, const Span& rhs );

#endif // SPAN_HPP
