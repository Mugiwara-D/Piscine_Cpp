#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"

#define OPEN_ERR "Error: invalid input"
#define INTERN_ERR "Error: invalid data.csv file"

using std::cout;
using std::endl;

float	ft_stof( const std::string& str );

int	ft_error( std::string msg )
{
	std::cerr << msg << endl;
	return 1;
}

int	main( int ac, char **av ) 
{
	if (ac != 2)
		return ft_error(OPEN_ERR);

	std::ifstream	input_db(av[1], std::ifstream::in);
	if (!input_db.is_open())
		return ft_error(OPEN_ERR);

	std::ifstream	intern_db("./data.csv", std::ifstream::in);
	if (!intern_db.is_open())
		return ft_error(INTERN_ERR);

	BitcoinExchange	btc(intern_db);

	std::string	line;
	std::getline(input_db, line);
	while (std::getline(input_db, line))
	{
		size_t	sep = line.find('|');
		if (sep == std::string::npos || line.length() < sep + 2) {
			std::cerr << "Bad input_db " << line  << std::endl;
			continue ;
		}
		std::string date = line.substr(0, sep - 1);
		if (!btc.checkDate(date))
			continue ;

		float price = ft_stof(line.substr(sep + 2));
		if (price < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (price > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		cout << date << " => " << price << " = " << std::setprecision(2) 
			<< std::fixed << price * btc.getPrice(date) << endl;
	}


	return 0;
}
