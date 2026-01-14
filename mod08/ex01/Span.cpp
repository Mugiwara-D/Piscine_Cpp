#include "Span.hpp"

Span::Span( void ) {
}

Span::Span( uint32_t n ) : _n(n){
}


Span::Span( const Span& src ) {
	*this = src;
}

Span& Span::operator=(const Span& src) {
	if (this != &src) {
		this->_n =src._n;
		this->_data_vect = src._data_vect;
	}

	return *this;
}

Span::~Span() {
}

void	Span::addNumber( int num ) {
	if (_data_vect.size() > _n)
		throw std::out_of_range("Span::addNumber _data_vector is full");
	_data_vect.push_back(num);
}

uint32_t	Span::longestSpan( void ) const {
	if (_data_vect.size() < 2)
		throw std::out_of_range("Span::longestSpan _data_vector as less than two element");
	return (*std::max_element(_data_vect.begin(), _data_vect.end()) 
			- *std::min_element(_data_vect.begin(), _data_vect.end()));
}

uint32_t	Span::shortestSpan( void ) const {
	if (_data_vect.size() < 2)
		throw std::out_of_range("Span::shortestSpan _data_vector as less than two element");

	uint32_t min = longestSpan();

	for (std::vector<int>::const_iterator i = _data_vect.begin();
			i != _data_vect.end(); i++)
	{
		for (std::vector<int>::const_iterator j = _data_vect.begin();
			j != _data_vect.end(); j++)
		{
			if (i == j)
				continue;
			if (std::abs(*j - *i) < static_cast<int>(min))
				min = std::abs(*j - *i);
		}
	}
	return min;
}

const std::vector<int>*	Span::getData( void ) const {
	return &_data_vect;
}

std::ostream&	operator<<( std::ostream& o, const Span& src ){
	for (std::vector<int>::const_iterator i = src.getData()->begin();
			i != src.getData()->end(); i++)
		o << *i << " ";
	return o;
}
