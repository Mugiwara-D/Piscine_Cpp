#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
	private :
		ScalarConverter() {}
		~ScalarConverter() {}
	public :
		static void	convert( const std::string& literal );
};

#endif // SCALARCONVERTER_HPP
