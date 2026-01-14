#include "BitcoinExchange.hpp"

static unsigned int ft_stou(const std::string& str)
{
    unsigned int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

BitcoinExchange::BitcoinExchange() {
    //std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& src ) {
	*this = src;
}
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& src ) {
	this->_data = src._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange( std::ifstream& intern_db )
{
	std::string	line;
	size_t		sep;
	while (std::getline(intern_db, line))
	{
		sep = line.find(',');

		float price = ft_stof(line.substr(sep + 1));
		std::string date = line.substr(0, sep);
		if (checkPrice(line.substr(sep + 1)) && checkDate(date))
			this->_data[date] = price;

	}
	intern_db.close();
}

bool	BitcoinExchange::checkPrice( std::string price )
{
	if (price.empty() || price.find_first_not_of("0123456789.-") != std::string::npos 
			|| price.at(0) == '.' || price.find('.', price.length() - 1) != std::string::npos)
		std::cerr << "Invalide price " << "\"" << price << "\"" << std::endl;
	else if (price.at(0) == '-')
		std::cerr << "Invalide: price must be positive" << "\"" << price << "\"" << std::endl;
	else if (price.length() > 10 || (price.length() == 10 && price > "2147483647"))
		std::cerr << "Invalide: price too long" << "\"" << price << "\"" << std::endl;
	else
		return true;
	return false;
}

bool	BitcoinExchange::checkDate( std::string date )
{
	std::string s;
	int year, month, day;
	std::istringstream ss(date);
	int i = 0;

	while (std::getline(ss, s, '-'))
	{
		if (i == 0)
		{
			year = ft_stou(s);
			if (year < 2009 || year > 2022)
			{
				std::cerr << "Invalide Year "<< "\"" << date << "\"" << '\n';
				return false;
			}
		}
		if (i == 1)
		{
			month = ft_stou(s);
			if (month < 1 || month > 12)
			{
				std::cerr << "Invalide Month" << "\"" << date << "\"" << '\n';
				return false;
			}
		}
		if (i == 2)
		{
			day = ft_stou(s);
			if ((day < 1 || day > 31)
			||  (day == 31 && (month == 2 || month == 4 || month == 6 
			|| month == 9 || month == 11))
			||  (day > 28 && month == 2))
			{
				std::cerr << "Invalide Day" << "\"" << date << "\"" << '\n';
				return false;
			}
		}
		i += 1;
	}
	if (i != 3)
	{
		std::cerr << "Invalide Date" << "\"" << date << "\"" << '\n';
		return false;
	}
	return true;
}

float	BitcoinExchange::getPrice( const std::string date )
{
	if (this->_data.count(date) > 0)
		return this->_data.at(date);
	float price = (--this->_data.lower_bound(date))->second;
	return price;
}
