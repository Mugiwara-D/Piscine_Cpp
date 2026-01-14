#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){	
}

std::string Contact::getInput(std::string str) const {
	std::string input = "";

	while (1){
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (!std::cin.good() && input.empty())
		{
			std::cin.clear();
			std::cout << "Invalid input, try again" << std::endl;
		}
		else
			return (input);
	}
	return "\0";
}

void	Contact::init(int i){
	std::cin.ignore();
	this->firstName = this->getInput("enter your first name pleas: ");
	if (this->firstName.compare("\0") == 0){
		std::cout << "\nctrl-D catch" << std::endl;
		return ;}
	this->lastName = this->getInput("enter your last (not first) Name: ");
	if (this->lastName.compare("\0") == 0){
		std::cout << "\nctrl-D catch" << std::endl;
		return ;}
	this->nickName = this->getInput("now the nickname: ");
	if (this->nickName.compare("\0") == 0){
		std::cout << "\nctrl-D catch" << std::endl;
		return ;}
	this->phoneNumber = this->getInput("ton 07 stp : ");
	if (this->phoneNumber.compare("\0") == 0){
		std::cout << "\nctrl-D catch" << std::endl;
		return ;}
	this->darkestSecret = this->getInput("quesque tu cache derier ce sourire: ");
	if (this->darkestSecret.compare("\0") == 0){
		std::cout << "\nctrl-D catch" << std::endl;
		return ;}
	this->index = i;
	std::cout << std::endl;
}

std::string	Contact::lineTrim(std::string str) const{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::display(int index) const {
	if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->lineTrim(this->firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->lineTrim(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->lineTrim(this->nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void Contact::showCon(int index) const {
	if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty())
		return ;
	std::cout << std::endl;
	std::cout << "Contact #" << index <<std::endl;
	std::cout << "First Name -> " << this->firstName <<std::endl;
	std::cout << "Last Name -> " << this->lastName <<std::endl;
	std::cout << "Nickname -> " << this->nickName <<std::endl;
	std::cout << "Number -> " << this->phoneNumber <<std::endl;
	std::cout << "Dark Secret ->" << this->darkestSecret <<std::endl;
	std::cout << std::endl;
}
