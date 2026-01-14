#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
//		int n;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(void);
		void	printContact(void) const;
		void	search(void);
		void	welcom(void) const;
		int		getIndex(void);
};

#endif
