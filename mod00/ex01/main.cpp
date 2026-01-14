#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void){
	PhoneBook book;
	std::string input = "";
	book.welcom();
	while(input.compare("EXIT")){
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0){
			book.printContact();
			book.search();
		}
		std::cout << "->" << std::flush;
		std::cin >> input;
		if (std::cin.eof())
			break ;
	}
	return (0);
}
