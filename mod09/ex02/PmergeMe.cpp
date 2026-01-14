#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
   // std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& src) {
	(void) src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	(void) src;
	return *this;
}

PmergeMe::~PmergeMe() {
}

static unsigned int	ft_stou( const std::string& str )
{
	unsigned int		num;
	std::stringstream	ss(str);

	ss >> num;
	return num;
}

bool	PmergeMe::setUp( int ac, char **av )
{
	for (int i = 1; i < ac; i++){
		for (unsigned int k = 0; k < _vect.size(); ++k) {
			if (_vect[k] == ft_stou(av[i])) {
				std::cout << RED << "Same terme detected: [" << YELLOW << av[i] << RED << "], aborting set up!" << RESET << std::endl;
				_vect.clear();
				_list.clear();
				return true;
			}
		}
		_vect.push_back(ft_stou(av[i]));
		_list.push_back(ft_stou(av[i]));
	}
	return false;
}

void	PmergeMe::setVect( std::vector<unsigned int> tmp ) {
	_vect = tmp;
}

void	PmergeMe::setList( std::list<unsigned int> tmp ) {
	_list = tmp;
}

void	PmergeMe::printList( void )
{
	std::cout << CYAN << "List of " << _list.size() << " elements" << std::endl;

	if (_list.size() <= 20) {
		for (std::list<unsigned int>::iterator i = _list.begin(); i != _list.end(); i++) {
			std::cout << *i << " ";
		}
	} else {
		std::list<unsigned int>::iterator it = _list.begin();
		for ( int i = 0 ; i < 10; ++i, ++it) {
			std::cout << *it << " ";
		}
		std::cout << "[...] " ;
		it = _list.end();
		for (int i = 0; i < 10; ++i) {
			it--;
		}
		for (int i = 0; i < 10; ++i, ++it){
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::printVect( void )
{
	std::cout << MAGENTA << "Vector of " << _vect.size() << " elements" << std::endl; 
	if (_vect.size() <= 20) {
		for(unsigned int i = 0; i < _vect.size(); i++) {
			std::cout << _vect[i] << " ";
		}
	} else {
		for (int i = 0; i < 10; ++i) {
			std::cout << _vect[i] << " ";
		}
		std::cout << "[...] ";
		for (unsigned int i = _vect.size() - 10; i < _vect.size(); ++i) {
			std::cout << _vect[i] << " ";
		}
	}
	std::cout << std::endl;
}

std::vector<unsigned int>	PmergeMe::getVect( void )
{
	return(this->_vect);
}

std::list<unsigned int>		PmergeMe::getList( void )
{
	return (this->_list);
}

void	PmergeMe::sortVect( std::vector<unsigned int> &arr )
{
	int	n = arr.size();
	if (n < 2)
		return;

	std::vector<unsigned int> left(arr.begin(), arr.begin() + (n/2));
	std::vector<unsigned int> right(arr.begin() + (n/2), arr.end());

	sortVect(left);
	sortVect(right);

	std::vector<unsigned int> merged;
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
			merged.push_back(left[i++]);
		else
			merged.push_back(right[j++]);
	}

	while (i < left.size())
		merged.push_back(left[i++]);
	while (j < right.size())
		merged.push_back(right[j++]);

	for (int k = 0; k < n; ++k)
		arr[k] = merged[k];

}

static std::list<unsigned int>	mergeList( const std::list<unsigned int> &left, const std::list<unsigned int> &right )
{
	std::list<unsigned int> ret;

	std::list<unsigned int>::const_iterator it1 = left.begin(), it2 = right.begin();

	while (it1 != left.end() && it2 != right.end())
	{
		if (*it1 < *it2) {
			ret.push_back(*it1);
			++it1;
		}
		else {
			ret.push_back(*it2);
			++it2;
		}
	}

	ret.insert(ret.end(), it1, left.end());
	ret.insert(ret.end(), it2, right.end());

	return ret;
}

void	PmergeMe::sortList( std::list<unsigned int> &arr )
{
	int	n = arr.size();
	if (n < 2)
		return ;

	std::list<unsigned int>::iterator mid = arr.begin();
	advance(mid, n / 2);
	std::list<unsigned int> left, right;

	for (std::list<unsigned int>::iterator it = arr.begin(); it != mid; ++it) {
        left.push_back(*it);
    }
    for (std::list<unsigned int>::iterator it = mid; it != arr.end(); ++it) {
        right.push_back(*it);
    }

	sortList(left);
	sortList(right);

	arr = mergeList(left, right);
}

const char*	PmergeMe::InvalidElemExp::what() const throw() {
	return "PmergeMe exception: Invalide element";
}
