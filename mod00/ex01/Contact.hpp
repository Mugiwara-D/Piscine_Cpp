#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		int			index;
		
	public:
		Contact();
		~Contact();
		std::string	getInput(std::string str) const;
		void	init(int i);
		std::string	lineTrim(std::string str) const;
		void	showCon(int index) const;
		void	display(int index) const;
		void	setIndex(int i);
};

#endif
