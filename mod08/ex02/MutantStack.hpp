#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		MutantStack( const MutantStack& src );
		MutantStack& operator=( const MutantStack& src );
		~MutantStack();

		iterator	begin( void );
		iterator	end( void );
};

template <typename T>
MutantStack<T>::MutantStack( void ){
#ifdef VERBOSE
	std::cout << "default constructor called" << std::endl;
#endif
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& src ){
	*this = src;
#ifdef VERBOSE
	std::cout << "copy constructor called" << std::endl;
#endif
}

template <typename T>
MutantStack<T>::~MutantStack( void ){
#ifdef VERBOSE
	std::cout << "default destructor called" << std::endl;
#endif
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& src ){
	std::stack<T>::operator=(src);
	return *this;
} 

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void ){
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void ){
	return this->c.end();
}

#endif // MUTANTSTACK_HPP
