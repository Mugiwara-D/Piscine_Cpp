#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <sstream>

enum literal_type {
	_error,
	_pseudoLiteral,
	_char,
	_int,
	_double,
	_float,
};

static int	ft_sti( const std::string& str ) {
	int	n;
	std::stringstream	ss(str);

	ss >> n;
	return n;
}

static float	ft_stf( const std::string& str ) {
	float	n;
	std::stringstream	ss(str);

	ss >> n;
	return n;
}

static double	ft_std( const std::string& str ) {
	double	n;
	std::stringstream	ss(str);

	ss >> n;
	return n;
}

static bool	isChar( const std::string& str ) {
	if (str.length() != 1 || 
		str.at(0) < std::numeric_limits<char>::min() ||
		str.at(0) > std::numeric_limits<char>::max() ||
		isdigit(str.at(0)))
		return false;
	return true;
}

static bool	isInt( const std::string& str ) {
	for (size_t i = str.at(0) == '-' ? 1 : 0; i < str.length(); i++) {
		if (!isdigit(str.at(i)))
			return false;
	}
	char *end;
	long tmp = strtol(str.c_str(), &end, 10);
	if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
		return false;
	return true;
}

static bool	isFloat( const std::string& str ) {
	bool point = false;

    for (size_t i = str.at(0) == '-' ? 1 : 0; i < str.length() - 1; i++) {

		if (str.at(i) == '.' && point)
			return false;
		else if (str.at(i) == '.'){
			point = true;
			continue;
		}
		if (!isdigit(str.at(i)))
            return false; 
	}
	if (str.at(str.length() - 1) != 'f')
		return false;
    return true;
}

static bool isDouble( const std::string& str ) {
	bool point = false;

    for (size_t i = str.at(0) == '-' ? 1 : 0; i < str.length() - 1; i++) {

		if (str.at(i) == '.' && point)
			return false;
		else if (str.at(i) == '.'){
			point = true;
			continue;
		}
		if (!isdigit(str.at(i)))
            return false; 
	}
    return true;
}

static bool isPseudoL( const std::string& str ) {
	if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf"
			|| str == "nan" || str == "nanf")
		return true;
	return false;
}

static literal_type	getType( const std::string& str ) {
	if (isChar(str))
		return _char;
	if (isInt(str))
		return _int;
	if (isFloat(str))
		return _float;
	if (isDouble(str))
		return _double;
	if (isPseudoL(str))
		return _pseudoLiteral;
	return _error;
}

static void	printChar( char c ) {
	std::cout << "\033[32m" << "CHAR: '" << c << "'" << "\033[0m" << std::endl;
	std::cout << "INT: " << static_cast<int>(c) << "" << std::endl;
	std::cout << "FLOAT: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "DOUBLE: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	printInt( int n ) {
	if (n < std::numeric_limits<int>::max() && n > std::numeric_limits<int>::min()){
		if (n > 35 && n < 127)
			std::cout << "CHAR: '" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "CHAR: Non displayable" << std::endl;
	} else
			std::cout << "CHAR: Non displayable" << std::endl;
	std::cout <<   "\033[32m" << "INT: " << n << "\033[0m" << std::endl;
	std::cout << "FLOAT: " << static_cast<float>(n) << ".0f" << std::setprecision(12) << std::endl;
	std::cout << "DOUBLE: " << static_cast<double>(n) << ".0" << std::endl;
}

static void	printFloat( float f ) {
	if (f < std::numeric_limits<int>::max() && f > std::numeric_limits<int>::min()){
		if (f > 35 && f < 127)
			std::cout << "CHAR: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "CHAR: Non displayable" << std::endl;
	} else
			std::cout << "CHAR: Non displayable" << std::endl;
	std::cout << "INT: " << static_cast<int>(f) << "" << std::endl;
	std::cout << std::setprecision(12) << 
		"\033[32m" << "FLOAT: " << f << "f" << "\033[0m" << std::endl;
	std::cout << "DOUBLE: " << static_cast<double>(f) << "" << std::endl;
}

static void	printDouble( double d ) {
	if (d < std::numeric_limits<int>::max() && d > std::numeric_limits<int>::min()){
		if (d > 35 && d < 127)
			std::cout << "CHAR: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "CHAR: Non displayable" << std::endl;
	} else
			std::cout << "CHAR: Non displayable" << std::endl;
	std::cout << "INT: " << static_cast<int>(d) << "" << std::endl;
	std::cout << "FLOAT: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "\033[32m" << "DOUBLE: " << d << "\033[0m" << std::endl;
}

static void	printPseudoLiteral( const std::string& str ) {
	std::cout << "CHAR: Non displayable" << std::endl;
	std::cout << "INT: Impossible" << std::endl;
	if (str == "nan" || str == "nanf") {
		if (str == "nan") {
			std::cout << "FLOAT: " << "nanf" << std::endl;
			std::cout << "\033[32m"  << "DOUBLE: " << "nan" << "\033[0m" << std::endl;
		}
		else {

			std::cout << "\033[32m"  << "FLOAT: " << "nanf" << "\033[0m" << std::endl;
			std::cout << "DOUBLE: " << "nan" << std::endl;
		}

	}
	else {
		if (str == "-inff" || str == "+inff")
			std::cout << "\033[32m" << "FLOAT: " << ((str == "-inf") ? "-inff" : "+inff")
				<< "\033[0m" << std::endl;
		else
			std::cout << "FLOAT: " << ((str == "-inf") ? "-inff" : "+inff") << std::endl;
		if (str == "-inf" || str == "+inf")
			std::cout << "\033[32m"  << "DOUBLE: " << ((str == "-inf") ? "-inf" : "+inf") 
				<< "\033[0m" << std::endl;
		else
			std::cout << "DOUBLE: " << ((str == "-inf") ? "-inf" : "+inf") << std::endl;
	}
}

void    ScalarConverter::convert( const std::string& literal ) {
	switch (getType(literal))
	{
		case _char:
			printChar(literal.at(0));
			break;

		case _int:
			printInt(ft_sti(literal));
			break;

		case _float:
			printFloat(ft_stf(literal));
			break;

		case _double:
			printDouble(ft_std(literal));
			break;

		case _pseudoLiteral:
			printPseudoLiteral(literal);
			break;

		default:
			std::cout << "WhAt TypE Is ThAT ?!" << std::endl;
			break;
	}
}
