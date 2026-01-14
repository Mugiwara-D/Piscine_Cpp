#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;

	public:
		BitcoinExchange();
		BitcoinExchange( std::ifstream& intern_db );
		BitcoinExchange( const BitcoinExchange& src );
		BitcoinExchange& operator=( const BitcoinExchange& src );
		~BitcoinExchange();

		float	getPrice( const std::string date );
		bool	checkPrice( std::string price );
		bool	checkDate( std::string date );
};

#endif // BITCOINEXCHANGE_HPP
