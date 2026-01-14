#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template <typename T>
class Array
{
	private:
		T	*_data;
		unsigned int _size;

	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array& src );
		~Array();

		Array& operator=( const Array& src );
		T& operator[]( unsigned int n );

		unsigned int	size( void ) const;
		class OutOfBoundsException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
};

template <typename T>
Array<T>::Array( void ) : _data(new T[0]()), _size(0) {}  

template <typename T>
Array<T>::Array( unsigned int n ) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array( const Array& src ) : _data(new T[src.size()]), _size(src.size()) {
	for (unsigned int i = 0; i < _size; ++i) {
		_data[i] = src._data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& src )
{
	delete[] this->_data;
	this->_data = new T[src._size];
	this->_size = src._size;
	for (unsigned int i; i < src._size; i++)
		this->_data[i] = src._data[i];
	return *this;
}

template <typename T>
T&	Array<T>::operator[]( unsigned int n )
{
	if (n >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return this->_data[n];
}

template <typename T>
Array<T>::~Array( void ) {
	delete[] this->_data;
}

template <typename T>
unsigned int	Array<T>::size( void ) const {
	return this->_size;
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what(void) const throw() {
	return "Array exception: Index out of bound ";
}
#endif // ARRAY_HPP
