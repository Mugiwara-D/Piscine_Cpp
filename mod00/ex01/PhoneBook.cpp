#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
}

PhoneBook::~PhoneBook(){
}

void	PhoneBook::welcom(void) const{
	std::cout << std::endl;
	std::cout << "welcom to your PhoneBook" << std::endl;
	std::cout << "<----------------------------->" << std::endl;
	std::cout << "Notice :" << std::endl;
	std::cout << "ADD\t: to add contact" << std::endl;
	std::cout << "SEARCH\t: to search contact" << std::endl;
	std::cout << "EXIT\t: to quit the Phonebook" << std::endl;
	std::cout << "<----------------------------->" << std::endl;

}

void	PhoneBook::addContact(void){
	static int	i;
	this->contact[i % 8].init(i);
	i++;
}

void	PhoneBook::printContact(void) const{
	std::cout << "<-> Phonebook preview <->" << std::endl;
	for (int i = 0; i < 8; i++){
		this->contact[i].display(i);
	}
	std::cout << std::endl;
}

int	PhoneBook::getIndex(){
	int	index = -1;
	while (1){
		std::cout << "enter Contact Index : " << std::endl;
		std::cin >> index;
		if (std::cin.good() && (index >= 0 && index < 8))
			return (index);
		else if (std::cin.eof())
			return (-1);
		else {
			std::cin.clear();
	        std::cin.ignore();
			std::cin.sync();
			std::cout << "Invalid entry: try again" << std::endl;
		}
	}
	return (index);
}

void	PhoneBook::search(void){
	int i = this->getIndex();
	if (i < 0 || i > 7)
		return ;
	this->contact[i].showCon(i);
}
