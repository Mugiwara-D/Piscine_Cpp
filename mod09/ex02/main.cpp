#include "PmergeMe.hpp"
#include <sstream>



int	main( int ac, char** av )
{
	if (ac == 2) {
		std::cout << "bad number of argument" << std::endl;
		return 1;
	}

	try
	{
		for (int i = 1; i < ac; i++){
			if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos){
				throw PmergeMe::InvalidElemExp();
			}
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::clock_t	start;
	std::clock_t	end;

	PmergeMe	pmm;

	if (pmm.setUp(ac, av))
		return 1;
	std::cout << RED << "Non sorted containers" << RESET <<std::endl;
	pmm.printVect();
	std::cout << std::endl;
	pmm.printList();

	std::cout << RED << "\n⏳bip" << GREEN << " boop " << CYAN << "i'm " << MAGENTA << "computing !⌛\n" << RESET << std::endl;

	start = std::clock();
	std::vector<unsigned int> tmp = pmm.getVect();
	pmm.sortVect(tmp);
	end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	double vectTime = elapsed;
	pmm.setVect(tmp);
	pmm.printVect();
	std::cout << "⏱️ " << GREEN << elapsed << BLUE << " second passed⏱️\n" << RESET << std::endl;

	start = std::clock();
	std::list<unsigned int> tmp2 = pmm.getList();
	pmm.sortList(tmp2);
	end = std::clock();
	elapsed = double(end - start) / CLOCKS_PER_SEC;
	double listTime = elapsed;
	pmm.setList(tmp2);
	pmm.printList();
	std::cout << "⏱️ " << GREEN << elapsed << BLUE << " second passed⏱️\n" << RESET << std::endl;
	std::cout << MAGENTA << "\nVector time was : " << GREEN << vectTime << " S" << RESET << std::endl;	
	std::cout << CYAN << "\nList time was : " << GREEN << listTime << " S" << RESET << std::endl;	

	return 0;
}
