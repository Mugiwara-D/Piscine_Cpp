#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <iterator>
#include <ctime>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class PmergeMe
{
	private:
		std::vector<unsigned int>	_vect;
		std::list<unsigned int>		_list;

	public:
		PmergeMe();
		PmergeMe( const PmergeMe& src );
		PmergeMe& operator=( const PmergeMe& src );
		~PmergeMe();

		bool	setUp( int ac, char **av );
		void	setVect( std::vector<unsigned int> tmp);
		void	setList( std::list<unsigned int> tmp);

		void	sortVect( std::vector<unsigned int> &arr );
		void	sortList( std::list<unsigned int> &arr );

		void	printVect( void );
		void	printList( void );

		std::vector<unsigned int> getVect(void);
		std::list<unsigned int> getList(void);

		class InvalidElemExp : public std::exception {
			public :
				virtual const char* what() const throw();
		};

};


#endif // PMERGEME_HPP
